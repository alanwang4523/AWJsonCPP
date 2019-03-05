cmake_minimum_required(VERSION 3.6)
project(JsonCPPDemo)

set(CMAKE_CXX_STANDARD 11)

include_directories(./jsoncpp/json/)

file(GLOB CPP_FILES_IN_LIB_JSON "./jsoncpp/lib_json/*.cpp")

set(SOURCE_FILES
        ${CPP_FILES_IN_LIB_JSON}
        main.cpp)
add_executable(JsonCPPDemo ${SOURCE_FILES})