cmake_minimum_required(VERSION 3.12)

# Project Name
project(
    CXXPythonDocs
    VERSION 0.0
    DESCRIPTION "Example documentation build for a project consisting of C++ libraries with python bindings."
    LANGUAGES CXX
)

#
# Discover dependencies.
#

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

#
# Build doxygen documentation.
#

# Configure Doxyfile.
set(INPUTS ${PROJECT_SOURCE_DIR}/src/mathTools)
set(DOXYGEN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/docs/doxygen)
string(REPLACE ";" " \\\n" DOXYGEN_INPUTS "${INPUTS}")
configure_file(
	doxygen/Doxyfile.in
	${DOXYGEN_OUTPUT_DIR}/Doxyfile
)

# Create doxygen command which produces a file output (in this case the index.xml).
# This depends on the source Doxyfile.in and configured Doxyfile.
add_custom_command(
	COMMAND
		${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUTPUT_DIR}/Doxyfile
	OUTPUT
		${DOXYGEN_OUTPUT_DIR}/xml/index.xml
	WORKING_DIRECTORY
		${CMAKE_BINARY_DIR}
	MAIN_DEPENDENCY
		${DOXYGEN_OUTPUT_DIR}/Doxyfile
		doxygen/Doxyfile.in
	COMMENT
		"Generating doxygen XML."
)

# Define a target which depends on the doxygen xml output file.
# This target is always built.
add_custom_target(
	doxygen_xml ALL
	DEPENDS
		${DOXYGEN_OUTPUT_DIR}/xml/index.xml
)

# XXX: Note that we do not need to install the doxygen XML output.
# They're an internal product which is consumed by the sphinx breathe plugin.

#
# Build sphinx documentation.
#

# Configure sphinx conf.py.
set(SPHINX_OUTPUT_DIR ${CMAKE_BINARY_DIR}/docs/sphinx)
configure_file(
	sphinx/conf.py.in
    ${SPHINX_OUTPUT_DIR}/conf.py
)

#
# Add source tree.
#

add_subdirectory(thirdparty)
add_subdirectory(src)
