include_directories(${GTEST_INCLUDE})

add_executable(01-strings-test 01-strings-test.cpp)
add_test(01-strings 01-strings-test)

target_link_libraries(01-strings-test gtest gtest_main)
target_link_libraries(01-strings-test 01-strings)
