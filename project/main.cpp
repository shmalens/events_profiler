#include <iostream>
#include <string>

#include "Date.h"

int main() {
    std::string dateString = "2021-05-12";
    profiler::Date date(dateString);
    std::cout << date << std::endl;
    return 0;
}