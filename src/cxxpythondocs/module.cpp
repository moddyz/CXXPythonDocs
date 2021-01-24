#include <pybind11/pybind11.h>

extern void BindVec3f(pybind11::module&);
extern void BindOperations(pybind11::module&);

PYBIND11_MODULE(cxxpythondocs, module)
{
    module.doc() = "cxxpythondocs python module.";
    BindVec3f(module);
    BindOperations(module);
}
