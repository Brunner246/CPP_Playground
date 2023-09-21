cmake_minimum_required(VERSION 3.25)
project(cadwork_plugin)

set(CMAKE_CXX_STANDARD 23)

add_definitions(-CWPLUGIN_EXPORTS)

add_library(${PROJECT_NAME} SHARED
        library.cpp
        library_api.h
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        LIBRARY
)


SET(CADLIB_DIR "C:/source/cadlib")

set(CADWORK_VERSION 30)

# set(CMAKE_PREFIX_PATH "${CADLIB_DIR}3rdParty/v_${CADWORK_VERSION}.0/Qt/x64/lib/cmake")

INCLUDE_DIRECTORIES("${CADLIB_DIR}/v_${CADWORK_VERSION}.0/3d/CwAPI3D")

target_compile_definitions(${PROJECT_NAME} PRIVATE
        CWPLUGIN_EXPORTS
        CWAPI3D_PLUGIN_NAME=L"Cadwork Test Plugin"
        CWAPI3D_AUTHOR_NAME=L"Michael Brunner"
        CWAPI3D_AUTHOR_EMAIL=L"brunner@cadwork.swiss"
)