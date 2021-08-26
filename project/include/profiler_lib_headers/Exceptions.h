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

        class DataBaseError : std::exception {
        public:
            const char *what() const noexcept override { return "Data Base exception"; }
        };

        class IncorrectDateEntry : public DataBaseError {
        public:
            explicit IncorrectDateEntry(const std::string &operation=DEFAULT_OPERATION_MSG);

            const char *what() const noexcept override { return format_message.get(); }

        private:
            std::unique_ptr<char> format_message;
        };
    }
}

#endif //PROFILER_EXCEPTIONS_H
