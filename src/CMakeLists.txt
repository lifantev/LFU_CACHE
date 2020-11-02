
cmake_minimum_required(VERSION 3.10)

project(lfu_cache VERSION 0.0.1 LANGUAGES C CXX)

add_library(lfu_cache STATIC lfu_cache.cpp lfu_cache.hpp)
