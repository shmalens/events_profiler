#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#include "DataBase.h"
#include "Date.h"
#include "Events.h"
#include "Exceptions.h"

namespace profiler {
    void DataBase::addImpl(const Date &date, const std::string &newNoteEvent) {
        if (!db[date].isEventExists(newNoteEvent)) {
            db[date].Add(newNoteEvent);
        }
//        if (db.count(date) == 1) {
//            db[date].Add(newNoteEvent);
//        } else {
//            Events ev;
//            ev.Add(newNoteEvent);
//            db.insert(std::pair<Date, Events>(date, ev));
//        }
    }

    void DataBase::Add(const Date &newNoteDate, const std::string &newNoteEvent) {
        addImpl(newNoteDate, newNoteEvent);
    }

    void DataBase::Add(const std::string &newNoteDate, const std::string &newNoteEvent) {
        try {
            const Date date(newNoteDate);
            addImpl(date, newNoteEvent);
        }
        catch (profiler::exceptions::DateInvalidDelimiter &ex) {
            throw profiler::exceptions::IncorrectDateEntry("Add");
        }
        catch (profiler::exceptions::DateInvalidFormat &ex) {
            throw profiler::exceptions::IncorrectDateEntry("Add");
        }
    }

    void DataBase::deleteDateImpl(const Date &removeDate) {
        db.erase(removeDate);
    }

    void DataBase::DeleteDate(const Date &removeDate) {
        deleteDateImpl(removeDate);
    }

    void DataBase::DeleteDate(const std::string &removeDate) {
        try {
            const Date date(removeDate);
            deleteDateImpl(date);
        }
        catch (profiler::exceptions::DateInvalidDelimiter &ex) {
            throw profiler::exceptions::IncorrectDateEntry("DeleteDate");
        }
        catch (profiler::exceptions::DateInvalidFormat &ex) {
            throw profiler::exceptions::IncorrectDateEntry("DeleteDate");
        }
    }

    void DataBase::deleteEventImpl(const Date &removeDate, const std::string &removeEvent) {
        db[removeDate].Delete(removeEvent);
    }

    void DataBase::DeleteEvent(const Date &removeDate, const std::string &removeEvent) {
        deleteEventImpl(removeDate, removeEvent);
    }

    void DataBase::DeleteEvent(const std::string &removeDate, const std::string &removeEvent) {
        try {
            const Date date(removeDate);
            deleteEventImpl(date, removeEvent);
        }
        catch (profiler::exceptions::DateInvalidDelimiter &ex) {
            throw profiler::exceptions::IncorrectDateEntry("DeleteEvent");
        }
        catch (profiler::exceptions::DateInvalidFormat &ex) {
            throw profiler::exceptions::IncorrectDateEntry("DeleteEvent");
        }
    }

    std::string DataBase::ShowDB() const {
        std::stringstream ss;
        for (const auto &[date, events]: db) {
            ss << date << ": " << events << std::endl;
        }
        return ss.str();
    }
}
