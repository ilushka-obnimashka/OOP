project(zoo)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 14)
add_executable(evolution main.cpp
        creatures.h
        visitor.h)