#include <pybind11/pybind11.h>

#include "vec3f.h"

using namespace cxxpythondocs;

void BindVec3f(pybind11::module& module)
{
    // Vec3f
    pybind11::class_<Vec3f> cls(module, "Vec3f");
    cls.def(pybind11::init<>(), "Default constructor.");
    cls.def(pybind11::init<float, float, float>(),
            "Component-wise constructor.");
    cls.def_property(
        "x",
        pybind11::cpp_function(
            [](Vec3f& vector) -> float& { return vector.X(); },
            pybind11::return_value_policy::reference_internal),
        pybind11::cpp_function(
            [](Vec3f& o_vector, const float& i_x) { o_vector.X() = i_x; }),
        "Accessor for x component.");
    cls.def_property(
        "y",
        pybind11::cpp_function(
            [](Vec3f& vector) -> float& { return vector.Y(); },
            pybind11::return_value_policy::reference_internal),
        pybind11::cpp_function(
            [](Vec3f& o_vector, const float& i_y) { o_vector.Y() = i_y; }),
        "Accessor for y component.");
    cls.def_property(
        "z",
        pybind11::cpp_function(
            [](Vec3f& vector) -> float& { return vector.Z(); },
            pybind11::return_value_policy::reference_internal),
        pybind11::cpp_function(
            [](Vec3f& o_vector, const float& i_z) { o_vector.Z() = i_z; }),
        "Accessor for z component.");
    cls.def("DotProduct", &Vec3f::DotProduct);
}
