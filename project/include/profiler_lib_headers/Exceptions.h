#ifndef PROFILER_EXCEPTIONS_H
#define PROFILER_EXCEPTIONS_H

#include <exception>
#include <memory>
#include <cstring>

#define DEFAULT_OPERATION_MSG "unknown"
#define DEFAULT_PART_MSG "Invalid date entry in operation: "

namespace profiler {
    namespace exceptions {
        class DateException : public std::exception {
        public:
            const char *what() const noexcept override { return "Date exception произошел"; }
        };

        class DateInvalidFormat : public DateException {
        public:
            const char *what() const noexcept override { return "Invalid date format"; }
        };

        class DateInvalidDelimiter : public DateInvalidFormat {
        public:
            const char *what() const noexcept override { return "Invalid date delimiter"; }
        };

        class DateInvalidMonth : public DateException {
        public:
            explicit DateInvalidMonth(int _month) : month(_month) {}

            const char *what() const noexcept override { return "Invalid date month entry"; }

            int GetValue() const { return month; }

        private:
            int month;
        };

        class DateInvalidDay : public DateException {
        public:
            explicit DateInvalidDay(int day) : day(day) {}

            const char *what() const noexcept override { return "Invalid date day entry"; }

            int GetValue() const { return day; }

        private:
            int day;
        };

        class DataBaseError : std::exception {
        public:
            const char *what() const noexcept override { return "Data Base exception"; }
        };

        class IncorrectDateEntry : public DataBaseError {
        public:
            explicit IncorrectDateEntry(const std::string &operation = DEFAULT_OPERATION_MSG);

            const char *what() const noexcept override { return format_message.get(); }

        private:
            std::unique_ptr<char> format_message;
        };
    }
}

#endif //PROFILER_EXCEPTIONS_H
