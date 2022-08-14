#pragma once

#include <vector>
#include <list>
#include <unordered_map>
#include <memory>
#include <string>

#include "Device.hpp"
#include "Room.hpp"

class Home {
    std::list<std::unique_ptr<Device>> devices;
    std::list<std::unique_ptr<Room>> rooms;
    std::unordered_map<std::string, decltype(devices.begin())> deviceNameMap;
    std::unordered_map<std::string, decltype(rooms.begin())> roomNameMap;

public:
    const std::list<std::reference_wrapper<Device>> getDevices();
    const std::list<std::reference_wrapper<Room>> getRooms();

    const Device& addDevice(std::unique_ptr<Device> device);
    void removeDevice(const Device& device);

    const Room& addRoom(const std::string& name);
    void removeRoom(const Room& room);

};
