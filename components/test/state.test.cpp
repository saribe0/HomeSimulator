#include <catch2/catch_test_macros.hpp>

#include "State.hpp"

std::string test_category = "[state]";
std::string name("state_name");

TEST_CASE("Test the constructors of an integer state", test_category ) {

    int val = 5;
    auto state = State(name, val);

    REQUIRE(state.name == name);
    REQUIRE(state.getValue() == val);
}

TEST_CASE("Test the constructors of a double state", test_category ) {

    double val = 5.0;
    auto state = State(name, val);

    REQUIRE(state.name == name);
    REQUIRE(state.getValue() == val);
}

TEST_CASE("Test the constructors of a boolean state", test_category ) {

    bool val = true;
    auto state = State(name, val);

    REQUIRE(state.name == name);
    REQUIRE(state.getValue() == val);
}

TEST_CASE("Test a generic state pointer to an integer state", test_category ) {

    int val = 5;
    State state = State(name, val);
    GenericState* genericState = &state;
    int testVal = 0;

    genericState->visitValue([&testVal](void* val){testVal = *(int *)val;});

    REQUIRE(genericState->name == name);
    REQUIRE(testVal == val);
}


TEST_CASE("Test a generic state pointer to a double state", test_category ) {

    double val = 5.0;
    State state = State(name, val);
    GenericState* genericState = &state;
    double testVal = 0.2;

    genericState->visitValue([&testVal](void* val){testVal = *(double *)val;});

    REQUIRE(genericState->name == name);
    REQUIRE(testVal == val);
}


TEST_CASE("Test a generic state pointer to a boolean state", test_category ) {

    bool val = true;
    State state = State(name, val);
    GenericState* genericState = &state;
    bool testVal = false;

    genericState->visitValue([&testVal](void* val){testVal = *(double *)val;});

    REQUIRE(genericState->name == name);
    REQUIRE(testVal == val);
}

TEST_CASE("Test a State object can not override it's value", test_category ) {

    double val = 5.0;
    State state = State(name, val);
    GenericState* genericState = &state;

    double newVal = 0.2;
    genericState->visitValue([&newVal](void* val){*(double *)val = newVal;});
    
    double testVal = 0.6;
    genericState->visitValue([&testVal](void* val){testVal = *(double *)val;});

    REQUIRE(genericState->name == name);
    REQUIRE(testVal == val);
}

TEST_CASE("Test the that an int setable state can be created and set", test_category ) {

    int val = 5;
    auto state = SetableState(name, val);

    REQUIRE(state.name == name);
    REQUIRE(state.getValue() == val);

    int newVal = 8;
    state.setValue(newVal);

    REQUIRE(state.getValue() == newVal);

}

TEST_CASE("Test the that an double setable state can be created and set", test_category ) {

    double val = 5.0;
    auto state = SetableState(name, val);

    REQUIRE(state.name == name);
    REQUIRE(state.getValue() == val);

    double newVal = 8.0;
    state.setValue(newVal);

    REQUIRE(state.getValue() == newVal);
}

TEST_CASE("Test the that an boolean setable state can be created and set", test_category ) {

    bool val = true;
    auto state = SetableState(name, val);

    REQUIRE(state.name == name);
    REQUIRE(state.getValue() == val);

    bool newVal = false;
    state.setValue(newVal);

    REQUIRE(state.getValue() == newVal);
}

TEST_CASE("Test a SetableState object can override it's value", test_category ) {

    double val = 5.0;
    SetableState state = SetableState(name, val);
    GenericState* genericState = &state;

    double newVal = 0.2;
    genericState->visitValue([&newVal](void* val){*(double *)val = newVal;});
    
    double testVal = 0.6;
    genericState->visitValue([&testVal](void* val){testVal = *(double *)val;});

    REQUIRE(genericState->name == name);
    REQUIRE(testVal == newVal);
}

