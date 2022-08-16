#include <iostream>

#include "HomeSimulatorCLI.hpp"

HomeSimulatorCLI::HomeSimulatorCLI(): CLI() {
    setPrompt("HomeSimulator> ");
    addCommand(Command("test", [](std::string args){std::cout << "test_command: " << args << "\n";}));
    addHelpCommand(Command("help", [](std::string args){std::cout << "help: " << args << "\n";}));
}

void HomeSimulatorCLI::getUserCommand() {
    CLI::getUserCommand();
}

