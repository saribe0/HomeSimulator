#include <catch2/catch_test_macros.hpp>

#include "Home.hpp"

std::string test_category = "[home]";

TEST_CASE( "Test the home can add and retrieve devices", test_category ) {

    auto home = Home();
    home.addDevice(std::make_unique<Device>("device1"));
    home.addDevice(std::make_unique<Device>("device2"));
    auto devices = home.getDevices();

    REQUIRE(devices.size() == 2);
}

TEST_CASE( "Test the home can add and retrieve rooms", test_category ) {

    auto home = Home();
    home.addRoom("test_room");
    auto rooms = home.getRooms();

    REQUIRE(rooms.size() == 1);
    REQUIRE(rooms.front().get().name == "test_room");
}

TEST_CASE( "Test the home can add and remove rooms", test_category ) {

    auto home = Home();
    home.addRoom("test_room1");
    auto newRoom = home.addRoom("test_room2");
    auto rooms = home.getRooms();
    REQUIRE(rooms.size() == 2);

    home.removeRoom(newRoom);
    rooms = home.getRooms();

    REQUIRE(rooms.size() == 1);
    REQUIRE(rooms.front().get().name == "test_room1");
}

TEST_CASE( "Test the home can add and remove devices", test_category ) {

    auto home = Home();
    home.addDevice(std::make_unique<Device>("device1"));
    auto newDevice = home.addDevice(std::make_unique<Device>("device2"));
    auto devices = home.getDevices();

    REQUIRE(devices.size() == 2);

    home.removeDevice(newDevice);
    devices = home.getDevices();

    REQUIRE(devices.size() == 1);
    REQUIRE(devices.front().get().name == "device1");
}

