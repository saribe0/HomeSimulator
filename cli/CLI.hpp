#pragma once
#include <string>
#include <unordered_map>

#include "Command.hpp"

class CLI {
    static constexpr char lineDeliminator = ' ';
    std::string line;
    std::string prompt;
    std::unordered_map<std::string, Command> commands;
    std::string helpCommand = "";

    bool commandRegistered(const std::string& command);
    void processLine();
    inline std::string parseCommand();
    inline std::string parseArgs();

public:
    void setPrompt(const std::string& prompt);
    void addCommand(const Command& command);
    void addHelpCommand(const Command& command);
    void setHelpCommand(const std::string& helpCommand);
    void getUserCommand();
    void executeCommand(const std::string& command, const std::string& args);
};

