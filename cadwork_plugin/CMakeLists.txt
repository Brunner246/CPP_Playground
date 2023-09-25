cmake_minimum_required(VERSION 3.9)
project(cadwork_plugin)

set(CMAKE_CXX_STANDARD 23)
SET(CADLIB_DIR "C:/source/cadlib")

set(CADWORK_VERSION 30)
#find_package(cpr REQUIRED)
#find_package(CURL REQUIRED)
find_package(cpprestsdk REQUIRED)

#set(LIBCURL_DLL_PATH "C:/cadwork.dir/EXE_30/pclib.x64")
#set(CPR_LIB_PATH "${CADLIB_DIR}/3rdParty/v_${CADWORK_VERSION}.0/cpr")
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/Users/Public/Documents/cadwork/userprofil_${CADWORK_VERSION}/3d/API.x64/cadwork_plugin/")

INCLUDE_DIRECTORIES(
        "${CADLIB_DIR}/v_${CADWORK_VERSION}.0/3d/CwAPI3D"
#        "${CADLIB_DIR}/3rdParty//v_${CADWORK_VERSION}.0/curl"
#        "${CPR_LIB_PATH}"
)


add_library(${PROJECT_NAME} SHARED
        library.cpp
        library_api.h
        TestModule.ixx
        IButton.h
        RestRequests.ixx
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        cpprestsdk::cpprest
        #cpr::cpr
        #CURL::libcurl
#       ${CPR_LIB_PATH}/3rdParty/v_${CADWORK_VERSION}/cpr/x64/cpr
#       ${CPR_LIB_PATH}/3rdParty/v_${CADWORK_VERSION}/curl/x64/libcurl
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        CWPLUGIN_EXPORTS
        CWAPI3D_PLUGIN_NAME=L"Cadwork Test Plugin"
        CWAPI3D_AUTHOR_NAME=L"Michael Brunner"
        CWAPI3D_AUTHOR_EMAIL=L"brunner@cadwork.swiss"
)

