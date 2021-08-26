#ifndef PROFILER_DATE_H
#define PROFILER_DATE_H

namespace profiler {
    class Date {
    public:
        Date() = default;

        explicit Date(const std::string &dateInString, char delimiter = '-');

        bool operator<(const Date &rhs) const;

        friend std::ostream &operator<<(std::ostream &os, const Date &outputDate);

        struct DateNumeric {
            int year;
            int month;
            int day;

            DateNumeric() : year(0), month(0), day(0) {}

            DateNumeric(int _year, int _month, int _day) : year(_year), month(_month), day(_day) {}
        };

    private:
        DateNumeric dateNumericRepresentation;
        std::string stringRepresentation;

        DateNumeric parseDate(const std::string &dateInString, char delimiter);

        static void validateStream(std::istream &is, char symbol);
    };

    std::ostream &operator<<(std::ostream &os, const Date &outputDate);
}

#endif //PROFILER_DATE_H
