cmake_minimum_required(VERSION 3.9)
project(cadwork_plugin)

set(CMAKE_CXX_STANDARD 23)
SET(CADLIB_DIR "C:/source/cadlib")

set(CADWORK_VERSION 30)

find_package(cpprestsdk REQUIRED)



INCLUDE_DIRECTORIES(
        "${CADLIB_DIR}/v_${CADWORK_VERSION}.0/3d/CwAPI3D"
        "${CADLIB_DIR}/3rdParty/v_${CADWORK_VERSION}.0/cpr"
)

link_directories(
        "${CADLIB_DIR}/3rdParty/v_${CADWORK_VERSION}.0/cpr/x64"
        "${CADLIB_DIR}/3rdParty/v_${CADWORK_VERSION}.0/curl/x64"
)


add_library(${PROJECT_NAME} SHARED
        library.cpp
        library_api.h
        TestModule.ixx
        IButton.h
        RestRequests.ixx
        Rest-Bridge/BridgeMain.h
        Rest-Bridge/Implementation/IBridgeImplementation.h
        Rest-Bridge/Implementation/CConcreteImplementationA.cpp
        Rest-Bridge/Implementation/CConcreteImplementationA.h
        Rest-Bridge/Abstraction/IBridgeAbstraction.h
        Rest-Bridge/Abstraction/CBridgeAbstraction.cpp
        Rest-Bridge/Abstraction/CBridgeAbstraction.cpp
        Rest-Bridge/Abstraction/CBridgeAbstraction.h
        Rest-Bridge/Implementation/CConcreteImplementationB.cpp
        Rest-Bridge/Implementation/CConcreteImplementationB.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        cpprestsdk::cpprest
        libcurl
        cpr
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        CWPLUGIN_EXPORTS
        CWAPI3D_PLUGIN_NAME=L"Cadwork Test Plugin"
        CWAPI3D_AUTHOR_NAME=L"Michael Brunner"
        CWAPI3D_AUTHOR_EMAIL=L"brunner@cadwork.swiss"
)

