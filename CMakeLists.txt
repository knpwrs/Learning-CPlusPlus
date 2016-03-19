cmake_minimum_required(VERSION 3.3)

project(learning-cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

enable_testing()
set(GTEST_INCLUDE ${CMAKE_SOURCE_DIR}/vendor/googletest/include)

add_subdirectory(01-professional-cplusplus)
add_subdirectory(vendor/googletest)
