cmake_minimum_required(VERSION 3.2)

project(learning-cpp)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

enable_testing()
set(GTEST_INCLUDE ${CMAKE_SOURCE_DIR}/vendor/googletest/include)

add_subdirectory(01-professional-cplusplus)
add_subdirectory(vendor/googletest)
