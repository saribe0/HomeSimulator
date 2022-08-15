
#include "Device.hpp"
#include "utils/utilities.hpp"

const std::list<std::reference_wrapper<State>> Device::getStates() {
    auto temp = toRefs<State>(setableStates);
    temp.splice(temp.end(), toRefs(getableStates));
    return temp;
}

const std::list<std::reference_wrapper<State>> Device::getGetableStates() {
    return toRefs(getableStates);
}

const std::list<std::reference_wrapper<SetableState>> Device::getSetableStates() {
    return toRefs(setableStates);
}
