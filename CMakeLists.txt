cmake_minimum_required(VERSION 3.23)
project(Graph LANGUAGES CXX)

add_executable(Graph app/main.cpp)

set_target_properties(Graph PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        PREFIX ""
        )

target_include_directories(Graph
        PUBLIC
        $<INSTALL_INTERFACE:include/>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

target_include_directories(Graph
        PRIVATE
        $<INSTALL_INTERFACE:interface/>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/interface>
        )

add_subdirectory(src)