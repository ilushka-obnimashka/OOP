cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(Cbuffer)
# GoogleTest требует как минимум C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
# Для Windows: Предотвратить переопределение настроек компилятора/линкера родительского проекта
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем библиотеку Cbuffer
if(POLICY CMP0076)
    cmake_policy(SET CMP0076 NEW)
endif()


add_library(Cbuffer INTERFACE)
target_sources(Cbuffer INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src/Cbuffer.h)


# Добавляем тестовое приложение
add_executable(Cb_test
        test/Constructor_Tests.cpp
        test/Operator_Tests.cpp
        test/Push_Pop_Front_Back_Tests.cpp
        test/BufferState_Tests.cpp
        test/Lineraize_Test.cpp
        test/Working_with_buffer_elements_Tests.cpp)

# Связываем тестовое приложение с библиотекой и GoogleTest
target_link_libraries(Cb_test PRIVATE Cbuffer GTest::gtest_main)

# Находим тесты
include(GoogleTest)
gtest_discover_tests(Cb_test)