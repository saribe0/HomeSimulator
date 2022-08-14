#include <catch2/catch_test_macros.hpp>

#include "State.hpp"

std::string test_category = "[state]";

TEST_CASE("Test the constructors of an integer state", test_category ) {

    std::string name("device_name");
    int val = 5;
    auto state = State(name, val);

    REQUIRE(state.name == name);
    REQUIRE(state.getValue() == val);
}

TEST_CASE("Test the constructors of a double state", test_category ) {

    std::string name("device_name");
    double val = 5.0;
    State state2 = State(name, val);
    GenericState* state = &state2;
    double testVal = 0.2;
    state->visitValue([&testVal](void* val){testVal = *(double *)val;});

    REQUIRE(state->name == name);
    REQUIRE(testVal == val);
}

TEST_CASE("Test the constructors of a boolean state", test_category ) {

    std::string name("device_name");
    bool val = true;
    auto state = State(name, val);

    REQUIRE(state.name == name);
    REQUIRE(state.getValue() == val);
}

// TEST_CASE("Test the generic state can't be created of a boolean state", test_category ) {

//     std::string name("device_name");
//     bool val = true;
//     GenericState state = GenericState(name);

//     REQUIRE(state.name == name);
// }


