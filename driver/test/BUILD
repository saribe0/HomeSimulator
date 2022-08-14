load("@bazel_skylib//rules:expand_template.bzl", "expand_template")

cc_test(
    name = "driver_test",
    srcs = ["driver.test.cpp"],
    defines = ["CATCH_CONFIG_MAIN"],
    deps = [
        "@catch2//:catch2",
        "@catch2//:catch2_main",
    ],
)
