#ifndef PROFILER_MANAGER_H
#define PROFILER_MANAGER_H

#include <string>
#include <vector>

#define ADD_CMD "Add"
#define DELETE_CMD "Delete"
#define FIND_CMD "Find"
#define PRINT_CMD "Print"

#define CMD "Print asd"

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

protected:
    Parser m_parser;
};

class StreamInputManager : public InputManager {
public:
    StreamInputManager() = delete;

    explicit StreamInputManager(std::istream &_is) : is(_is) {}

    Command GetCommand() override;

    bool IsGood() const;

private:
    std::istream &is;
};

#endif //PROFILER_MANAGER_H
