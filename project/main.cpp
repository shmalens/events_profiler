#include <iostream>
#include <string>

#include "Date.h"
#include "Events.h"

int main() {
    std::string dateString = "2021-05-12";
    profiler::Date date(dateString);
    std::cout << date << std::endl;

    profiler::Events events({"ev1", "ev2", "ev3"});
    std::cout << events << std::endl;
    return 0;
}