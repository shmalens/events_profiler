#include <iostream>
#include <sstream>
#include <string>

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
            std::cerr << "FAIL" << std::endl;
            throw profiler::exceptions::DateInvalidFormat();
        }

        if (is.peek() != symbol) {
            std::cerr << "DELIMITER: " << is.peek() << std::endl;
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
        validateStream(parsingStream, delimiter);
        parsingStream >> resultDate.day;
        validateStream(parsingStream, EOF);

        return resultDate;
    }

    Date::Date(const std::string &dateInString, char delimiter) {
        dateNumericRepresentation = parseDate(dateInString, delimiter);
        stringRepresentation = dateInString;
    }

    bool Date::operator<(const Date &rhs) const {
        if (this->dateNumericRepresentation.year > rhs.dateNumericRepresentation.year) {
            return false;
        }

        if (this->dateNumericRepresentation.month > rhs.dateNumericRepresentation.month) {
            return false;
        }

        if (this->dateNumericRepresentation.day > rhs.dateNumericRepresentation.day) {
            return false;
        }

        if (this->dateNumericRepresentation.day == rhs.dateNumericRepresentation.day &&
            this->dateNumericRepresentation.month == rhs.dateNumericRepresentation.month &&
            this->dateNumericRepresentation.year == rhs.dateNumericRepresentation.year) {
            return false;
        }

        return true;
    }

    std::ostream &operator<<(std::ostream &os, const Date &outputDate) {
        os << outputDate.dateNumericRepresentation.year << '-'
           << outputDate.dateNumericRepresentation.month << '-'
           << outputDate.dateNumericRepresentation.day;
        return os;
    }
}
