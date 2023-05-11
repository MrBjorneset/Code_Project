
add_executable(Objects_test Objects.cpp)
add_test(NAME Objects_test COMMAND Objects_test)
target_link_libraries(Objects_test PRIVATE Catch2::Catch2WithMain threepp::threepp)
target_include_directories(Objects_test PUBLIC "${CMAKE_SOURCE_DIR}/include")

add_executable(Movement_test Movement.cpp)
add_test(NAME Movement_test COMMAND Movement_test)
target_link_libraries(Movement_test PRIVATE Catch2::Catch2WithMain threepp::threepp)
target_include_directories(Movement_test PUBLIC "${CMAKE_SOURCE_DIR}/include")