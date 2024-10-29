cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем опцию включения/отключения тестов
option(BUILD_TEST "Build test" ON)

include(FetchContent)
FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем библиотеку
add_library(HW_class_time src/class_time.cpp)


if(BUILD_TEST)

    # Добавляем тестовое приложение
    # Добавляем тестовое приложение
    add_executable(
            time_test
            test/CreationTest.cpp
            test/OperatorTest.cpp
    )

    # Связываем тестовое приложение с библиотекой и GoogleTest
    target_link_libraries(time_test PRIVATE HW_class_time GTest::gtest_main)

    # Находим тесты
    include(GoogleTest)
    gtest_discover_tests(time_test)
else ()
    add_executable(class_time src/class_time.cpp)
    target_link_libraries(class_time PRIVATE HW_class_time)

endif()