cmake_minimum_required(VERSION 3.10)

project(LFUtest VERSION 0.0.1 LANGUAGES C CXX)

add_executable(LFUtest LFUtest.cpp)

target_link_libraries(LFUtest PUBLIC
    gtest_main
    LFUCache
)

add_test(
    NAME LFUtest
    COMMAND LFUtest
)