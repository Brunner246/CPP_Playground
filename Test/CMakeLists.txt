cmake_minimum_required(VERSION 3.25)
project(UnitTest)

set(CMAKE_CXX_STANDARD 23)

add_executable(UnitTest
        main.cpp
        )

find_package(doctest CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Library
        doctest::doctest
        )