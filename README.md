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

## Building

Example snippet for building this project:
```
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX="/apps/CXXPythonDocs/" ..
make install -j8
```
