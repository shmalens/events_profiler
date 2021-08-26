#ifndef PROFILER_DISPATCHER_H
#define PROFILER_DISPATCHER_H

#include "DataBase.h"

class Dispatcher {
public:
    Dispatcher() = delete;
    explicit Dispatcher(profiler::DataBase &_db) : db(_db) {}

    void dispatch();

private:
    profiler::DataBase &db;

};

#endif //PROFILER_DISPATCHER_H
