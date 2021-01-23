cmake_minimum_required(VERSION 3.12)

# Project Name
project(
    CXXPythonDocs
    VERSION 0.0
    DESCRIPTION "Example documentation build for a project consisting of C++ libraries with python bindings."
    LANGUAGES CXX
)

# Discover python.
find_package(Python COMPONENTS Development Interpreter)
message(STATUS "Found python executable: ${Python_EXECUTABLE}")

# Discover doxygen.
find_program(DOXYGEN_EXECUTABLE
    NAMES doxygen
)
if (EXISTS ${DOXYGEN_EXECUTABLE})
	message(STATUS "Found doxygen executable: ${DOXYGEN_EXECUTABLE}")
else()
	message(FATAL_ERROR "doxygen executable found.")
endif()

# Discover sphinx.
find_program(SPHINX_EXECUTABLE
    NAMES sphinx-build
)
if (EXISTS ${SPHINX_EXECUTABLE})
	message(STATUS "Found sphinx executable: ${SPHINX_EXECUTABLE}")
else()
	message(FATAL_ERROR "sphinx executable not found.")
endif()

# Add targets.
add_subdirectory(thirdparty)
add_subdirectory(src)
