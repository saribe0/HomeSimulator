#pragma once

#include <string>
#include <list>
#include <memory>
#include <functional>

#include "State.hpp"

class Device {
    std::list<std::unique_ptr<State>> getableStates;
    std::list<std::unique_ptr<SetableState>> setableStates;

public:
    const std::string name;
    Device(const std::string& name): name(name) {}

    const std::list<std::reference_wrapper<State>> getStates();
    const std::list<std::reference_wrapper<State>> getGetableStates();
    const std::list<std::reference_wrapper<SetableState>> getSetableStates();

};
