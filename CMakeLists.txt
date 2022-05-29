cmake_minimum_required(VERSION 3.15)
project(Graph VERSION 1.1.0 LANGUAGES CXX)

#########################
# Create & Link Library #
#########################

add_library(${PROJECT_NAME} INTERFACE)
add_library(GRon::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

add_executable(graph_exe app/main.cpp)
target_link_libraries(graph_exe PRIVATE GRon::Graph)

set_target_properties(${PROJECT_NAME} graph_exe PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        PREFIX ""
        )

target_include_directories(${PROJECT_NAME}
        INTERFACE
        $<INSTALL_INTERFACE:include/>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

###################
# Install Library #
###################

include(GNUInstallDirs)
set(INSTALL_CONFIG_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
        ARCH_INDEPENDENT
)
configure_package_config_file(
        ${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
        ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        INSTALL_DESTINATION ${INSTALL_CONFIG_DIR}
)

install(EXPORT ${PROJECT_NAME}Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE GRon::
        DESTINATION ${INSTALL_CONFIG_DIR}
        )

install(FILES
        ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION ${INSTALL_CONFIG_DIR}
        )

install(DIRECTORY include/GRon DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

export(
        EXPORT ${PROJECT_NAME}Targets
        NAMESPACE GRon::
        FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake
)

set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
export(PACKAGE ${PROJECT_NAME})