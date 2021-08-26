#include <iostream>

#include "DataBase.h"
#include "Dispatcher.h"

int main() {
    profiler::DataBase db;
    Dispatcher dispatcher(db);
    dispatcher.dispatch();

    return 0;
}