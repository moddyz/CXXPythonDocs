# For standard installation directory variables.
include(GNUInstallDirs)

# Library name.
set(LIBRARY_NAME "cxxpythondocs")

#
# C++ library.
#

# Install public headers.
set(PUBLIC_HEADERS
    vec3f.h
    operations.h
)

file(
	COPY ${PUBLIC_HEADERS}
    DESTINATION ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_NAME}
)

install(
	FILES ${PUBLIC_HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_NAME}
)

# Add a new library target.
add_library(${LIBRARY_NAME}
	SHARED
)

# Add C++ sources.
target_sources(${LIBRARY_NAME}
	PRIVATE
		vec3f.cpp
		operations.cpp
		${PUBLIC_HEADERS}
)

install(
    TARGETS ${LIBRARY_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)


#
# Python module.
#

set(PYMODULE_TARGET "_${LIBRARY_NAME}")

add_library(${PYMODULE_TARGET}
    MODULE
)

target_sources(${PYMODULE_TARGET}
	PRIVATE
		module.cpp
		bindVec3f.cpp
)

target_include_directories(${PYMODULE_TARGET}
	PRIVATE
		${Python_INCLUDE_DIRS}
)

target_link_libraries(${PYMODULE_TARGET}
	PRIVATE
		${LIBRARY_NAME}
		pybind11
		${Python_LIBRARIES}
)

# Strip lib prefix.
set_target_properties(${PYMODULE_TARGET} PROPERTIES PREFIX "")

# Set actual module name.
set_target_properties(${PYMODULE_TARGET}
	PROPERTIES
		OUTPUT_NAME ${LIBRARY_NAME}
)

install(
    TARGETS ${PYMODULE_TARGET}
	LIBRARY DESTINATION pylib
)

add_custom_command(
    TARGET ${PYMODULE_TARGET}
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DIR}/pylib
        COMMAND ${CMAKE_COMMAND} -E create_symlink $<TARGET_FILE:${PYMODULE_TARGET}> ${PROJECT_BINARY_DIR}/pylib/$<TARGET_FILE_NAME:${PYMODULE_TARGET}>
)
