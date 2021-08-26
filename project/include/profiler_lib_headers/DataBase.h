#ifndef PROFILER_DATABASE_H
#define PROFILER_DATABASE_H

#include <map>

#include "Date.h"
#include "Events.h"

namespace profiler {
    class DataBase {
    public:
        DataBase() = default;

        void Add(const std::string &newNoteDate, const std::string &newNoteEvent);
        void Add(const Date &newNoteDate, const std::string &newNoteEvent);

        void DeleteDate(const std::string &removeDate);
        void DeleteDate(const Date &removeDate);

        void DeleteEvent(const std::string &removeDate, const std::string &removeEvent);
        void DeleteEvent(const Date &removeDate, const std::string &removeEvent);

        std::string ShowDB() const;

    private:
        std::map<Date, Events> db;

        void addImpl(const Date &date, const std::string &newNoteEvent);
        void deleteDateImpl(const Date &removeDate);
        void deleteEventImpl(const Date &removeDate, const std::string &removeEvent);
    };
}

#endif //PROFILER_DATABASE_H
