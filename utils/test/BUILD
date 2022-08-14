load("@bazel_skylib//rules:expand_template.bzl", "expand_template")

cc_test(
    name = "utilities_test",
    srcs = [
        "utilities.test.cpp",
    ],
    copts = [
        "-Iutils/",
        "-Icomponents/"
    ],
    deps = [
        "@catch2//:catch2",
        "@catch2//:catch2_main",
        "//utils:utils",
        "//components:components",
    ],
)
