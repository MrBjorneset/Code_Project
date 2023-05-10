cmake_minimum_required(VERSION 3.15)
project(Code_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")


find_package(threepp CONFIG REQUIRED)
add_executable(PingPong main.cpp)
target_link_libraries(PingPong PRIVATE threepp::threepp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# stuff for testing
find_package(Catch2 CONFIG REQUIRED)
add_executable(Objects_test tests/Objects_test.cpp)
target_link_libraries(Objects_test PRIVATE Catch2::Catch2WithMain threepp::threepp)
add_executable(Movement_test tests/Movement_test.cpp)
target_link_libraries(Movement_test PRIVATE Catch2::Catch2WithMain threepp::threepp)



