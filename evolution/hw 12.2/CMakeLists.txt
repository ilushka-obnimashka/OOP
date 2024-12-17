project(evolution)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
add_executable(evolution main.cpp
        creatures.h
        "creature squad.h"
        food.h
        factory.h)