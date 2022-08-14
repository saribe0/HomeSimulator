#include <catch2/catch_test_macros.hpp>

#include "Device.hpp"

std::string test_category = "[device]";

TEST_CASE("Test the public members of a device", test_category ) {

    std::string name("device_name");
    auto device = Device(name);

    REQUIRE(device.name == name);
}
