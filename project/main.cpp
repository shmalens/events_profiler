#include <iostream>
#include <sstream>
#include <vector>

#include "Manager.h"

int main() {
    StreamInputManager si(std::cin);

    while (si.IsGood()) {
        Command cmd = si.GetCommand();

        std::cout << cmd.type << std::endl;
        std::cout << cmd.arg1 << std::endl;
        std::cout << cmd.arg2 << std::endl;
    }

    return 0;
}