load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "home_sim_cli",
    srcs = [
        "main.cpp",
        "HomeSimulatorCLI.cpp",
        "HomeSimulatorCLI.hpp"
    ],
    copts = [
        "-Icli/"
    ],
    deps = [
        "//cli:cli",
    ],
    visibility = ["//visibility:public"],
)
