cmake_minimum_required(VERSION 3.21)
project(lab08)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab08
        linkedlist.cpp
        linkedlist.hpp
        main.cpp)
