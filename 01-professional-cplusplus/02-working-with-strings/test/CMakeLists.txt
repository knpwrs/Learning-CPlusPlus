include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()

add_executable(01-strings-test 01-strings-test.cpp)

target_link_libraries(01-strings-test gtest gtest_main)
target_link_libraries(01-strings-test 01-strings)
