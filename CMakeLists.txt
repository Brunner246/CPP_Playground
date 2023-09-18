cmake_minimum_required(VERSION 3.25)
project(CPP_Playground)

set(CMAKE_CXX_STANDARD 23)

add_executable(CPP_Playground main.cpp
        Stack/stack.cpp
        Stack/stack.h
        Constructors/CBox3d.cpp
        Constructors/CBox3d.h
        Constructors/CCustomArray.h
        Heap/CUser.h
        Heap/CUser.cpp
        Modules/Playground.ixx Modules/Playground.Test.ixx)
