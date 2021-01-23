#include "vec3f.h"

namespace cxxpythondocs {

float Vec3f::DotProduct(const Vec3f& other) const
{
    return (m_x * other.m_x) + (m_y * other.m_y) + (m_z * other.m_z);
}

} // namespace cxxpythondocs

