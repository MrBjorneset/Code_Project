cmake_minimum_required(VERSION 3.15)
project(Code_Project)

set(CMAKE_CXX_STANDARD 17)

# Stuff for testing
include(FetchContent)
FETCHCONTENT_DECLARE(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)
FETCHCONTENT_MAKEAVAILABLE(Catch2)
enable_testing()
#
find_package(threepp CONFIG REQUIRED)
add_executable(PingPong main.cpp tests/test.cpp)
target_link_libraries(PingPong PRIVATE threepp::threepp)


find_package(catch2 REQUIRED)
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE my_library Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)

