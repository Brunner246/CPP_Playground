cmake_minimum_required(VERSION 3.25)
project(CPP_Playground)

set(CMAKE_CXX_STANDARD 23)

SET(CADLIB_DIR "C:/source/cadlib")

set(CADWORK_VERSION 30)


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
        Classes/OperatorOverloading/StructCast.h
        Random/ScopeRAII.h
        Classes/OOD/CEntity.h
        Classes/OOD/CValue.h
        Concepts/CDividable.h
        Concepts/CPoint3D.h
        Modules/AirlineTicket.ixx
        Modules/ModuleInterfaceUnit.ixx
        Modules/ModuleExample.ixx
        ProxyObjects/CVec3D.ixx
        Modules/Abstract/MInterface.ixx
        Modules/Abstract/MImplementation1.ixx
        Concepts/CNotNullptr.h
        ProxyObjects/ExtensionMethod.h
        ParallelProgramming/MAccount.ixx
        ParallelProgramming/FuturePromises.ixx
        ProxyObjects/CWriteReadLazy.h)


target_link_libraries(${PROJECT_NAME} PRIVATE
        Library
        cpr::cpr
        )

target_compile_definitions(${PROJECT_NAME} PRIVATE
        PARALLEL
)