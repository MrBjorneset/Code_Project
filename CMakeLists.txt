cmake_minimum_required(VERSION 3.15)
project(Code_Project)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)
# Stuff for testing
include(FetchContent)
FETCHCONTENT_DECLARE(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.8
)
FETCHCONTENT_MAKEAVAILABLE(Catch2)
enable_testing()
add_subdirectory(tests)
#
add_executable(PingPong main.cpp)
target_link_libraries(PingPong PRIVATE threepp::threepp)
