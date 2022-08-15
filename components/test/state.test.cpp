#include <catch2/catch_test_macros.hpp>

#include "State.hpp"

std::string test_category = "[state]";
std::string name("state_name");

TEST_CASE("Test the constructors of an integer state", test_category ) {

    int val = 5;
    auto state = State(name, val);

    REQUIRE(state.name == name);
    REQUIRE(std::get<decltype(val)>(state.getValue()) == val);
}

TEST_CASE("Test the constructors of a double state", test_category ) {

    double val = 5.0;
    auto state = State(name, val);

    REQUIRE(state.name == name);
    REQUIRE(std::get<decltype(val)>(state.getValue()) == val);
}

TEST_CASE("Test the constructors of a boolean state", test_category ) {

    bool val = true;
    auto state = State(name, val);

    REQUIRE(state.name == name);
    REQUIRE(std::get<decltype(val)>(state.getValue()) == val);
}

TEST_CASE("Test the that an int setable state can be created and set", test_category ) {

    int val = 5;
    auto state = SetableState(name, val);

    REQUIRE(state.name == name);
    REQUIRE(std::get<decltype(val)>(state.getValue()) == val);

    int newVal = 8;
    state.setValue(newVal);

    REQUIRE(std::get<decltype(val)>(state.getValue()) == newVal);

}

TEST_CASE("Test the that an double setable state can be created and set", test_category ) {

    double val = 5.0;
    auto state = SetableState(name, val);

    REQUIRE(state.name == name);
    REQUIRE(std::get<decltype(val)>(state.getValue()) == val);

    double newVal = 8.0;
    state.setValue(newVal);

    REQUIRE(std::get<decltype(val)>(state.getValue()) == newVal);
}

TEST_CASE("Test the that an boolean setable state can be created and set", test_category ) {

    bool val = true;
    auto state = SetableState(name, val);

    REQUIRE(state.name == name);
    REQUIRE(std::get<decltype(val)>(state.getValue()) == val);

    bool newVal = false;
    state.setValue(newVal);

    REQUIRE(std::get<decltype(val)>(state.getValue()) == newVal);
}

