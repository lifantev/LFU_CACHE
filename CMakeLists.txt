
cmake_minimum_required(VERSION 3.10)

project(final VERSION 0.0.1 LANGUAGES C CXX)

add_subdirectory(src)
add_subdirectory(googletest)

#option(TEST "Enable testing" OFF)

#if (TEST)
    add_executable(testing test.cpp)
    target_include_directories(testing PRIVATE lfu_cache)
    target_link_libraries(testing PRIVATE gtest gtest_main)
#else ()
#    add_executable(main main.cpp)
#    target_include_directories(main PRIVATE lfu_cache)
#    target_link_libraries(main PRIVATE lfu_cache)
#endif()