#ifndef PROFILER_EVENTS_H
#define PROFILER_EVENTS_H

#include <string>
#include <iostream>
#include <vector>

namespace profiler {
    class Events {
    public:
        Events() = default;

        explicit Events(const std::vector<std::string> &initVector) : events(initVector) {}

        void Add(const std::string &newEvent) { events.push_back(newEvent); }

        bool Delete(const std::string &removeEvent);

        const std::vector<std::string> &ConstStorageRef() const { return events; }

        std::vector<std::string> &StorageRef() { return events; }

        friend std::ostream &operator<<(std::ostream &os, const Events &ev);

        std::vector<std::string>::iterator Find(const std::string &str);

        bool isEventExists(const std::string &str);

        size_t Size() const { return events.size(); }

    private:
        std::vector<std::string> events;
    };

    std::ostream &operator<<(std::ostream &os, const Events &ev);
}

#endif //PROFILER_EVENTS_H
