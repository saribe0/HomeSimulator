#include <string>
#include <list>

#include "State.hpp"

class Device {
    std::list<std::unique_ptr<GenericState>> getableStates;
    std::list<std::unique_ptr<GenericState>> setableStates;

public:
    std::string name;
    Device(const std::string& name): name(name) {}



};
