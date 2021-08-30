#ifndef PROFILER_MANAGER_H
#define PROFILER_MANAGER_H

#include <string>
#include <vector>

#include "DataBase.h"

#define ADD_CMD "Add"
#define DELETE_CMD "Del"
#define FIND_CMD "Find"
#define PRINT_CMD "Print"

enum CommandTypes {
    UNEXPECTED,
    EMPTY,
    ADD,              // 2
    DELETE_DATE,
    DELETE_EVENT,
    FIND,
    PRINT
};

struct Command {
    int type;
    std::string arg1;
    std::string arg2;
};

class Parser {
public:
    Parser() = default;

    Command operator()(const std::string &cmd);

private:
    std::vector<std::string> split(const std::string &str);
};

class InputManager {
public:
    InputManager() = default;

    virtual Command GetCommand() = 0;

    virtual bool IsGood() const { return true; };

protected:
    Parser m_parser;
};

class StreamInputManager : public InputManager {
public:
    StreamInputManager() = delete;

    explicit StreamInputManager(std::istream &_is) : is(_is) {}

    Command GetCommand() override;

    bool IsGood() const override;

private:
    std::istream &is;
};

class Dispatcher {
public:
    Dispatcher() = delete;
    Dispatcher(profiler::DataBase &_db, InputManager &_manager) : db(_db), manager(_manager) {}

    void Dispatch();

private:
    profiler::DataBase &db;
    InputManager &manager;
};

#endif //PROFILER_MANAGER_H
