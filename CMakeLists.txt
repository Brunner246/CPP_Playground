cmake_minimum_required(VERSION 3.25)
project(CPP_Playground)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(Library)
add_subdirectory(Test)
add_subdirectory(cadwork_plugin)

find_package(cpr CONFIG REQUIRED)

add_executable(CPP_Playground
        main.cpp
        Stack/stack.cpp
        Stack/stack.h
        Classes/Constructors/CBox3d.cpp
        Classes/Constructors/CBox3d.h
        Classes/Constructors/CCustomArray.h
        Heap/CUser.h
        Heap/CUser.cpp
        Modules/Playground.ixx
        Modules/Playground.Test.ixx
        Modules/Position.ixx
        Stack/StackMain.cpp
        Stack/StackMain.h Classes/OperatorOverloading/FreeOperator.h
        Random/WrapDelete.h
        Random/WrapDelete.h
        Classes/OperatorOverloading/StructCast.h)


target_link_libraries(${PROJECT_NAME} PRIVATE
        Library
        cpr::cpr
        )

