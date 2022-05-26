cmake_minimum_required(VERSION 3.23)
project(UndirectedGraph LANGUAGES CXX)

add_executable(UndirectedGraph app/main.cpp)

set_target_properties(UndirectedGraph PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        PREFIX ""
        )

target_include_directories(UndirectedGraph
        PUBLIC
        $<INSTALL_INTERFACE:include/>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

target_include_directories(UndirectedGraph
        PRIVATE
        $<INSTALL_INTERFACE:interface/>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/interface>
        )

add_subdirectory(src)