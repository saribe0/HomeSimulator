#pragma once

#include <string>

using StateType = std::variant<int, double, float, bool, std::string>;

class State {
protected:
    StateType value;

public:
    const std::string name;

    template<typename T>
    constexpr State(const std::string& name, const T& value): value(value), name(name) {}
    
    const StateType getValue() { return value; }
};

class SetableState: public State {

public:
    template<typename T>
    constexpr SetableState(const std::string& name, const T& value): State(name, value) {}

    template<typename T>
    void setValue(const T& value) {
        this->value = value;
    }
};
