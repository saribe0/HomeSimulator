#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <typeinfo>
#include <catch2/catch_template_test_macros.hpp>

#include "Device.hpp"
#include "Room.hpp"
#include "utilities.hpp"

std::string test_category = "[utilities]";

TEMPLATE_PRODUCT_TEST_CASE( "toRefs converts a container of smart pointers to references", test_category, (std::vector, std::list, std::deque), (std::unique_ptr<Device>, std::unique_ptr<Room>, std::shared_ptr<float>)) {

    auto container = TestType();
    container.insert(container.end(), typename TestType::value_type());
    auto refs = toRefs(container);

    REQUIRE(refs.size() == 1);
    REQUIRE(std::is_same<typename TestType::value_type::element_type&, decltype(refs.front().get())>::value);
}
