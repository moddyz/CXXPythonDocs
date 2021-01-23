# For standard installation directory variables.
include(GNUInstallDirs)

# Library name.
set(LIBRARY_NAME "mathTools")

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
