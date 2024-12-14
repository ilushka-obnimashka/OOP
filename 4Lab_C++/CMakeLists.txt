CMAKE_MINIMUM_REQUIRED(VERSION 3.22)
project(4lab)

set(CMAKE_CXX_STANDARD 17)
add_executable(4lab main.cpp
        print_tuple.h
        CSVParser.h)