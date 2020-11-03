cmake_minimum_required(VERSION 3.10)

project(LFUCache VERSION 0.0.1 LANGUAGES C CXX)

add_library(LFUCache STATIC LFUCache.cpp LFUCache.hpp)
