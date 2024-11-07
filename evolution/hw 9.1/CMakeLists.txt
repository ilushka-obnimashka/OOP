cmake_minimum_required(VERSION 3.22)
project(evolution)

set(CMAKE_CXX_STANDARD 17)

add_executable(evolution main.cpp
        creatures.h)