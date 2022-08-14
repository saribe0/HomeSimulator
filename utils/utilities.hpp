#pragma once

#include <memory>

template<template <typename, typename> class Container, typename Object, template<typename> class Allocator, typename AllocatorObject>
auto toRefs(const Container<Object, Allocator<AllocatorObject>> &container) {
    typedef std::reference_wrapper<typename Object::element_type> ObjectReferenceType;
    Container<ObjectReferenceType, Allocator<ObjectReferenceType>> refs;
    std::transform(container.begin(), container.end(), std::back_inserter(refs), [](auto &x) { return std::ref(*x); });
    return refs;
}
