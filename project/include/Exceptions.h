#ifndef PROFILER_EXCEPTIONS_H
#define PROFILER_EXCEPTIONS_H

#include <exception>

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
    }
}

#endif //PROFILER_EXCEPTIONS_H
