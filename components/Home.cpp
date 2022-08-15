
#include "Home.hpp"
#include "utils/utilities.hpp"

const Device& Home::addDevice(std::unique_ptr<Device> device) {
    devices.push_front(std::move(device));
    deviceNameMap[devices.front()->name] = devices.begin();
    return *devices.front();
}

void Home::removeDevice(const Device& device) {
    devices.erase(deviceNameMap[device.name]);
    deviceNameMap.erase(device.name);
}

const Room& Home::addRoom(const std::string& name) {
    rooms.push_front(std::make_unique<Room>(name));
    roomNameMap[name] = rooms.begin();
    return *rooms.front();
}

void Home::removeRoom(const Room& room) {
    rooms.erase(roomNameMap[room.name]);
    roomNameMap.erase(room.name);
}

const std::list<std::reference_wrapper<Device>> Home::getDevices() {
    return toRefs(devices);
}

const std::list<std::reference_wrapper<Room>> Home::getRooms() {
    return toRefs(rooms);
}


