#
function(create_test name)
    add_executable(${name} ${name}.cpp)
    add_test(NAME ${name} COMMAND ${name})
    target_include_directories(${name} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
    target_link_libraries(${name} PRIVATE Catch2::Catch2WithMain threepp::threepp)
endfunction()

create_test(Objects)




