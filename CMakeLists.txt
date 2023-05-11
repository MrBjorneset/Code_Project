cmake_minimum_required(VERSION 3.15)
project(Code_Project)

set(CMAKE_CXX_STANDARD 17)


find_package(threepp CONFIG REQUIRED)
add_executable(PingPong main.cpp)
target_link_libraries(PingPong PRIVATE threepp::threepp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# stuff for testing
find_package(Catch2 CONFIG REQUIRED)


enable_testing()
add_subdirectory(tests)



