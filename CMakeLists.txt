
cmake_minimum_required(Version 3.10)

project(final VERSION 0.0.1 LANGUAGES C CXX)

add_subdirectory(src)
find_package(GTest REQUIRED)
add_subdirectory(test)

option(TEST OFF)

if (TEST)
    add_executable(test test.cpp)
    target_include_directories(test PRIVATE lfu_cache)
    target_link_libraries(lfu_cache test GTest::GTest GTest::Main)
else ()
    add_executable(main main.cpp)
    target_include_directories(main PRIVATE lfu_cache)
    target_link_libraries(lfu_cache main)