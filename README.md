<a href="https://github.com/moddyz/CXXPythonDocs/actions?query=workflow%3A%22Build+and+test%22"><img src="https://github.com/moddyz/CXXPythonDocs/workflows/Build%20and%20test/badge.svg"/></a>

# CXXPythonDocs

Example documentation build for a project consisting of C++ libraries with python bindings.

## Table of Contents

- [Dependencies](#dependencies)
- [Building](#building)

### Dependencies

The following dependencies are mandatory:
- C++ compiler
- [CMake](https://cmake.org/documentation/) (3.12 or greater)
- [Python](https://www.python.org/) 
- [Doxygen](https://www.doxygen.nl/index.html) and [graphiviz](https://graphviz.org/)
- [Sphinx](https://www.sphinx-doc.org/) 

## Building

Example snippet for building this project:
```
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX="/apps/CXXPythonDocs/" ..
make install -j8
```

## TODOs

- Discover and bail cmake configure if breathe is not installed.
- Sphinx build process should depend on doxygen XML build.
- Add python bindings
- C++ and Python side by side view.
