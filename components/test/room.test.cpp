#include <catch2/catch_test_macros.hpp>

#include "Room.hpp"

std::string test_category = "[room]";

TEST_CASE("Test the public members of a room", test_category ) {

    std::string name("room_name");
    auto room = Room(name);

    REQUIRE(room.name == name);
}
