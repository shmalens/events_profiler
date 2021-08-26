#include <memory>

#include <Exceptions.h>

namespace profiler {
    namespace exceptions {
        IncorrectDateEntry::IncorrectDateEntry(const std::string &operation) {
            std::string default_part = DEFAULT_PART_MSG;
            size_t msg_size = default_part.size() + operation.size();
            format_message = std::unique_ptr<char>(new char[msg_size]);
            std::string final_message = default_part + operation;
            std::strcpy(format_message.get(), final_message.c_str());
        }
    }
}

