cmake_minimum_required(VERSION 3.25)
project(PJ2_checkpointB)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PJ2_checkpointB
        ItemToPurchase.cpp
        ItemToPurchase.h
        main.cpp
        ShoppingCart.cpp
        ShoppingCart.h)
