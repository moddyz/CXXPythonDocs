cmake_minimum_required(VERSION 3.12)

# Project Name
project(
    CXXPythonDocs
    VERSION 0.0
    DESCRIPTION "Example documentation build for a project consisting of C++ libraries with python bindings."
    LANGUAGES CXX
)

# Set module search paths.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
# Apply options.
include(Options)

# Tools
include(Tools)

# Apply project defaults.
include(Defaults)

# Discover dependencies.
include(Packages)

# Add targets.
add_subdirectory(thirdparty)
add_subdirectory(src)

# Install exported targets.
export_project(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in)
