cmake_minimum_required(VERSION 3.25)
project(Library)

set(CMAKE_CXX_STANDARD 23)


add_definitions(-LIBRARY)

add_library(Library
        Library_Api.cpp
        Library_Api.h
        ITestInterface.h
        MTestModule.ixx
        CTestInterface.cpp
        CTestInterface.h)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        LIBRARY
        )

