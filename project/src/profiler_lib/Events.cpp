#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

#include "Events.h"

namespace profiler {
    void Events::Delete(const std::string &removeEvent) {
        events.erase(std::remove(events.begin(), events.end(), removeEvent), events.end());
    }

    std::ostream &operator<<(std::ostream &os, const Events &ev) {
        for (const auto &event: ev.events) {
            os << event << ' ';
        }
        return os;
    }

    std::vector<std::string>::iterator Events::Find(const std::string &str) {
        return std::find(events.begin(), events.end(), str);
    }

    bool Events::isEventExists(const std::string &str) {
        return Find(str) != events.end();
    }
}
