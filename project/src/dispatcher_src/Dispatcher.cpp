#include "Dispatcher.h"

#include <iostream>
#include <string>

#include "DataBase.h"
#include "Exceptions.h"

#define EOL 10

#define ADD_CMD "Add"
#define DELETE_CMD "Delete"
#define FIND_CMD "Find"
#define PRINT_CMD "Print"

void Dispatcher::dispatch() {
    std::string cmd;

    while (!std::cin.eof()) {
        std::cin >> cmd;
        if (cmd == ADD_CMD) {
            std::string stringDate, event;
            std::cin >> stringDate >> event;

            try {
                profiler::Date date(stringDate);
                db.Add(date, event);
            }
            catch (profiler::exceptions::DateInvalidDelimiter &idelim) {
                std::cout << "Wrong date format: " << stringDate << std::endl;
            }
            catch (profiler::exceptions::IncorrectDateEntry &ide) {

            }
        } else if (cmd == DELETE_CMD) {
            std::string stringDate;
            std::cin >> stringDate;

            try {
                if (std::cin.peek() != 10) {
                    std::string event;
                    std::cin >> event;

                    profiler::Date date(stringDate);
                    db.DeleteEvent(date, event);
                } else {
                    profiler::Date date(stringDate);
                    db.DeleteDate(date);
                }
            }
            catch (profiler::exceptions::DateInvalidDelimiter &idelim) {
                std::cout << "Wrong date format: " << stringDate << std::endl;
            }
            catch (profiler::exceptions::IncorrectDateEntry &ide) {

            }
        } else if (cmd == PRINT_CMD) {
            std::cout << db.ShowDB();
        } else {
            if (std::cin.peek() != EOL) {
                std::string tmp;
                std::getline(std::cin, tmp);
            }
            std::cout << "Unknown command: " << cmd << std::endl;
        }


    }
}