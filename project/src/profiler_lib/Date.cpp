#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "Date.h"
#include "Exceptions.h"

namespace profiler {
    /*
     * касательного этого метода мне
     * не совсем ясно, по идее
     * его надо убирать из класса, так как
     * он не трогает члены класса, но может
     * его оставить прямо тут, тк
     * он нужен для этого класса
     * */
    void Date::validateStream(std::istream &is, char symbol) {
        if (is.fail()) {
            throw profiler::exceptions::DateInvalidFormat();
        }

        if (is.peek() != symbol) {
            throw profiler::exceptions::DateInvalidDelimiter();
        } else {
            is.get();
        }
    }

    Date::DateNumeric Date::parseDate(const std::string &dateInString, char delimiter) {
        std::stringstream parsingStream(dateInString);

        DateNumeric resultDate;
        parsingStream >> resultDate.year;
        validateStream(parsingStream, delimiter);
        parsingStream >> resultDate.month;
        if (resultDate.month < 1 || resultDate.month > 12) {
            throw profiler::exceptions::DateInvalidMonth(resultDate.month);
        }
        validateStream(parsingStream, delimiter);
        parsingStream >> resultDate.day;
        if (resultDate.day < 1 || resultDate.day > 31) {
            throw profiler::exceptions::DateInvalidDay(resultDate.day);
        }
        validateStream(parsingStream, EOF);

        return resultDate;
    }

    Date::Date(const std::string &dateInString, char delimiter) {
        dateNumericRepresentation = parseDate(dateInString, delimiter);
        stringRepresentation = dateInString;
    }

    bool Date::operator==(const Date &rhs) const {
        return (this->dateNumericRepresentation.day == rhs.dateNumericRepresentation.day &&
                this->dateNumericRepresentation.month == rhs.dateNumericRepresentation.month &&
                this->dateNumericRepresentation.year == rhs.dateNumericRepresentation.year);
    }

    bool Date::operator<(const Date &rhs) const {
//        if (*this == rhs) {
//            return false;
//        }
//
//        if (this->dateNumericRepresentation.year > rhs.dateNumericRepresentation.year) {
//            return false;
//        }
//
//        if (this->dateNumericRepresentation.day > rhs.dateNumericRepresentation.day) {
//            return false;
//        }
//
//        if (this->dateNumericRepresentation.day > rhs.dateNumericRepresentation.day) {
//            return false;
//        }
//
//        return true;
         const DateNumeric tdm = this->dateNumericRepresentation;
         const DateNumeric rdm = rhs.dateNumericRepresentation;

        return std::tie(tdm.year, tdm.month, tdm.day) < std::tie(rdm.year, rdm.month, rdm.day);
    }

    std::ostream &operator<<(std::ostream &os, const Date &outputDate) {
        os << std::setw(4) << std::setfill('0') << outputDate.dateNumericRepresentation.year << '-'
           << std::setw(2) << std::setfill('0') << outputDate.dateNumericRepresentation.month << '-'
           << outputDate.dateNumericRepresentation.day;
        return os;
    }
}
