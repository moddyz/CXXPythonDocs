add_library(
    pybind11
    IMPORTED
    INTERFACE
    GLOBAL
)

target_include_directories(
    pybind11
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
