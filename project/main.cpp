#include <iostream>
#include <sstream>

#include "Manager.h"
#include "DataBase.h"
#include "Date.h"

int main() {
    StreamInputManager manager(std::cin);
    profiler::DataBase db;
    Dispatcher dispatcher(db, manager);

    dispatcher.Dispatch();
    return 0;
}