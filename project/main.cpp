#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "Date.h"
#include "Events.h"
#include "DataBase.h"
#include "Exceptions.h"

int main() {
//    profiler::Date date1("2020-03-04");
//    profiler::Date date2("2020-03-01");

    try {
        std::string date1 = "2020-03-04";
        std::string date2 = "2020-03-01";

        std::string ev1 = "ev1";
        std::string ev2 = "ev2";

        profiler::DataBase db;
        db.Add(date1, ev1);
        db.Add(date1, ev1);
        db.Add(date1, ev2);

        db.Add(date2, ev2);
        db.Add(date2, ev2);
        db.Add(date2, ev1);

        std::cout << db.ShowDB() << std::endl;

        db.DeleteEvent(date1, ev2);

        std::cout << db.ShowDB() << std::endl;
    }
    catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }


    return 0;
}