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

    size_t DataBase::deleteDateImpl(const Date &removeDate) {
        size_t date_events_amount = db[removeDate].Size();
        db.erase(removeDate);
        return date_events_amount;
    }

    size_t DataBase::DeleteDate(const Date &removeDate) {
        return deleteDateImpl(removeDate);
    }

    size_t DataBase::DeleteDate(const std::string &removeDate) {
        try {
            const Date date(removeDate);
            return deleteDateImpl(date);
        }
        catch (profiler::exceptions::DateInvalidDelimiter &ex) {
            throw profiler::exceptions::IncorrectDateEntry("DeleteDate");
        }
        catch (profiler::exceptions::DateInvalidFormat &ex) {
            throw profiler::exceptions::IncorrectDateEntry("DeleteDate");
        }
    }

    bool DataBase::deleteEventImpl(const Date &removeDate, const std::string &removeEvent) {
        bool res_val = db[removeDate].Delete(removeEvent);
        if (db[removeDate].Size() == 0) {
            deleteDateImpl(removeDate);
        }
        return res_val;
    }

    bool DataBase::DeleteEvent(const Date &removeDate, const std::string &removeEvent) {
        return deleteEventImpl(removeDate, removeEvent);
    }

    bool DataBase::DeleteEvent(const std::string &removeDate, const std::string &removeEvent) {
        try {
            const Date date(removeDate);
            return deleteEventImpl(date, removeEvent);
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
