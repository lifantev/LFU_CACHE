cmake_minimum_required(VERSION 3.10)

project(Main VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

enable_testing()
add_subdirectory(googletest)

add_subdirectory(src)
add_subdirectory(test)