
add_executable(Objects_test Objects.cpp)
target_link_libraries(Objects_test PRIVATE Catch2::Catch2WithMain threepp::threepp)
add_executable(Movement_test Movement.cpp)
target_link_libraries(Movement_test PRIVATE Catch2::Catch2WithMain threepp::threepp)