workspace(name = "HomeSimulator")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazel_skylib",
    strip_prefix = "bazel-skylib-2a87d4a62af886fb320883aba102255aba87275e",
    urls = [
        "https://github.com/bazelbuild/bazel-skylib/archive/2a87d4a62af886fb320883aba102255aba87275e.tar.gz",
    ],
    sha256 = "d847b08d6702d2779e9eb399b54ff8920fa7521dc45e3e53572d1d8907767de7",
)

http_archive(
    name = "catch2",
    strip_prefix = "Catch2-3.1.0",
    urls = [
        "https://github.com/catchorg/Catch2/archive/v3.1.0.tar.gz"
    ],
    sha256 = "c252b2d9537e18046d8b82535069d2567f77043f8e644acf9a9fffc22ea6e6f7",
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")
bazel_skylib_workspace()
