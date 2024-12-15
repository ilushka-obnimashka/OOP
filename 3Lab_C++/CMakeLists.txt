cmake_minimum_required(VERSION 3.22)
project(3Lab_C++)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES main.cpp
        ArgumentParser.h
        ArgumentParser.cpp)
add_executable(3Lab_C++ ${SOURCES})
