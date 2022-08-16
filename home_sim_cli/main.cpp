#include <iostream>

#include "HomeSimulatorCLI.hpp"

int main()
{
    auto homeSimCLI = HomeSimulatorCLI();
    do {
        homeSimCLI.getUserCommand();
    } while (true);

    std::cout << "Goodbye.\n";
}
