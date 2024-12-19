project(car)
cmake_minimum_required(VERSION 3.22)

SET(CMAKE_CXX_STANDARD 17)
add_executable(car main.cpp
        gears.h
        car.h)