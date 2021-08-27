#include "Manager.h"

#include <sstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> Parser::split(const std::string &str) {
    std::stringstream ss(str);
    std::vector<std::string> splitLine;
    while (ss) {
        std::string tmp;
        ss >> tmp;
        splitLine.push_back(tmp);
    }
    splitLine.pop_back();
    return splitLine;
}

Command Parser::operator()(const std::string &cmd) {
    Command resultCmd;

    std::vector<std::string> args = split(cmd);

    if (args.size() == 0) {
        resultCmd.type = EMPTY;
        return resultCmd;
    }

    if (args[0] == ADD_CMD) {
        if (args.size() != 3) {
            resultCmd.type = CommandTypes::UNEXPECTED;
            return resultCmd;
        }

        resultCmd.type = CommandTypes::ADD;
        resultCmd.arg1 = args[1];
        resultCmd.arg2 = args[2];
        return resultCmd;
    }

    if (args[0] == DELETE_CMD) {
        if (args.size() < 2) {
            resultCmd.type = CommandTypes::UNEXPECTED;
            return resultCmd;
        }

        if (args.size() == 3) {
            resultCmd.type = CommandTypes::DELETE_EVENT;
            resultCmd.arg1 = args[1];
            resultCmd.arg2 = args[2];
            return resultCmd;
        }

        if (args.size() == 2) {
            resultCmd.type = CommandTypes::DELETE_DATE;
            resultCmd.arg1 = args[1];
            return resultCmd;
        }
    }

    if (args[0] == FIND_CMD) {
        if (args.size() != 2) {
            resultCmd.type = CommandTypes::UNEXPECTED;
            return resultCmd;
        }

        resultCmd.type = CommandTypes::FIND;
        resultCmd.arg1 = args[1];
        return resultCmd;
    }

    if (args[0] == PRINT_CMD) {
        if (args.size() != 1) {
            resultCmd.type = CommandTypes::UNEXPECTED;
            return resultCmd;
        }

        resultCmd.type = CommandTypes::PRINT;
        return resultCmd;
    }

    resultCmd.type = CommandTypes::UNEXPECTED;
    return resultCmd;
}

Command StreamInputManager::GetCommand() {
    std::string cmd;
    std::getline(is, cmd);
    return m_parser(cmd);
}

bool StreamInputManager::IsGood() const {
    return is.good();
}