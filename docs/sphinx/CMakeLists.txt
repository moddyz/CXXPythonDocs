# Configure sphinx conf.py.
set(SPHINX_OUTPUT_DIR ${CMAKE_BINARY_DIR}/docs/sphinx)
configure_file(
	conf.py.in
    ${SPHINX_OUTPUT_DIR}/conf.py
)

