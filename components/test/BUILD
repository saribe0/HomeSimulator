load("@bazel_skylib//rules:expand_template.bzl", "expand_template")

cc_test(
    name = "home_test",
    srcs = [
        "home.test.cpp",
    ],
    copts = [
        "-Icomponents/"
    ],
    deps = [
        "@catch2//:catch2",
        "@catch2//:catch2_main",
        "//components:components",
    ],
)

cc_test(
    name = "room_test",
    srcs = [
        "room.test.cpp",
    ],
    copts = [
        "-Icomponents/"
    ],
    deps = [
        "@catch2//:catch2",
        "@catch2//:catch2_main",
        "//components:components",
    ],
)

cc_test(
    name = "device_test",
    srcs = [
        "device.test.cpp",
    ],
    copts = [
        "-Icomponents/"
    ],
    deps = [
        "@catch2//:catch2",
        "@catch2//:catch2_main",
        "//components:components",
    ],
)

cc_test(
    name = "state_test",
    srcs = [
        "state.test.cpp",
    ],
    copts = [
        "-Icomponents/"
    ],
    deps = [
        "@catch2//:catch2",
        "@catch2//:catch2_main",
        "//components:components",
    ],
)
