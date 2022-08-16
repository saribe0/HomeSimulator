#include "Command.hpp"

Command& Command::operator=(const Command& otherCommand) {
    return *this;
}

void Command::processCommand(const std::string& args) {
    commandFunc(args);
}
