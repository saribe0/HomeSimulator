#include <iostream>

#include "CLI.hpp"

void CLI::setPrompt(const std::string& prompt) {
    this->prompt = prompt;
}

void CLI::addCommand(const Command& command) {
    commands.insert(std::make_pair(command.command, command));
}

void CLI::setHelpCommand(const std::string& helpCommand) {
    if (commandRegistered(helpCommand)) {
        this->helpCommand = helpCommand;
    }
}

void CLI::addHelpCommand(const Command& command) {
    addCommand(command);
    setHelpCommand(command.command);
}

bool CLI::commandRegistered(const std::string& command) {
    return commands.contains(command);
}

void CLI::getUserCommand() {

    std::cout << prompt << " ";
    std::getline(std::cin, line);

    if (!line.empty()) {
        processLine(); 
    }
}

inline std::string CLI::parseCommand() {
    return line.substr(0, line.find(lineDeliminator));
}

inline std::string CLI::parseArgs() {
    auto deliminatorPos = line.find(lineDeliminator);
    return (deliminatorPos == std::string::npos) ? "" : line.substr(deliminatorPos, line.size());
}

void CLI::executeCommand(const std::string& command, const std::string& args) {
    commands.at(command).processCommand(args);
}

void CLI::processLine() {
    auto command = parseCommand();
    if (commandRegistered(command)) {
        executeCommand(command, parseArgs());
    }
    else if (!helpCommand.empty() && commandRegistered(helpCommand)) {
        executeCommand(helpCommand, "");
    }
}
