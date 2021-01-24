#include <pybind11/pybind11.h>

#include "operations.h"

using namespace cxxpythondocs;

void BindOperations(pybind11::module& module)
{
    module.def("AddIntegers", &AddIntegers, "Compute the sum of two integers.");
}
