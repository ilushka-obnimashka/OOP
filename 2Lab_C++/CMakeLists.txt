cmake_minimum_required(VERSION 3.14)

project(GameOfLife)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

set(RAYLIB_VERSION "4.5.0")

set(RAYLIB_URL "https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.zip")

FetchContent_Declare(
        raylib
        URL ${RAYLIB_URL}
)
FetchContent_MakeAvailable(raylib)


find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)


if (NOT OpenGL_FOUND)
    message(FATAL_ERROR "Необходимые зависимости для сборки Raylib с использованием OpenGL не найдены. Пожалуйста, установите следующие пакеты:\n\n"
            "sudo apt-get update\n"
            "sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev\n")
endif()

if (NOT X11_FOUND)
    message(FATAL_ERROR "Необходимые зависимости для сборки Raylib с использованием X11 не найдены. Пожалуйста, установите следующие пакеты:\n\n"
            "sudo apt-get update\n"
            "sudo apt-get install libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libxext-dev\n")
endif()


add_executable(GameOfLife main.cpp
        Universe.h
        Universe.cpp
        Simulation.h
        Simulation.cpp
        FileHandler.h
        FileHandler.cpp
        ArgumentParser.h
        ArgumentParser.cpp
        Game.h
        Game.cpp)

target_link_libraries(GameOfLife raylib)
