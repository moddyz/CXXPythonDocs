# Configure Doxyfile.
set(INPUTS ${PROJECT_SOURCE_DIR}/src/mathTools)
set(DOXYGEN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/docs/doxygen)
string(REPLACE ";" " \\\n" DOXYGEN_INPUTS "${INPUTS}")
configure_file(
	Doxyfile.in
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
		Doxyfile.in
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
