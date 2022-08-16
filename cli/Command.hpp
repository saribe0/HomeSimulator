#pragma once

#include <string>
#include <functional>

class Command {
    std::function<void (std::string args)> commandFunc;

public: 
    const std::string command;
    Command(const std::string& command, std::function<void(std::string args)> func): commandFunc(func), command(command)  {}
    Command(const Command& otherCommand): commandFunc(otherCommand.commandFunc), command(otherCommand.command) {}
    Command& operator=(const Command& otherCommand);
    void processCommand(const std::string& args);
};
