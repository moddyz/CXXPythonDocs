#pragma once

namespace cxxpythondocs {

/// \class Vec3f
///
/// A vector class with 3 floating-point components.
class Vec3f
{
public:
    // -----------------------------------------------------------------------
    /// \name Construction
    // -----------------------------------------------------------------------

    /// Default constructor.
    Vec3f() = default;

    /// Component-wise constructor.
    ///
    /// \param x The x element.
    /// \param y The y element.
    /// \param z The z element.
    inline explicit Vec3f(float x, float y, float z)
      : m_x(x)
      , m_y(y)
      , m_z(z)
    {}

    // -----------------------------------------------------------------------
    /// \name Component accessors
    // -----------------------------------------------------------------------

    /// Read-only accessor for the x component.
    ///
    /// \return The x component.
    inline float X() const { return m_x; }

    /// Read-only accessor for the y component.
    ///
    /// \return The y component.
    inline float Y() const { return m_y; }

    /// Read-only accessor for the z component.
    ///
    /// \return The z component.
    inline float Z() const { return m_z; }

    /// Mutable accessor for the x component.
    ///
    /// \return The x component.
    inline float& X() { return m_x; }

    /// Mutable accessor for the y component.
    ///
    /// \return The y component.
    inline float& Y() { return m_y; }

    /// Mutable accessor for the z component.
    ///
    /// \return The z component.
    inline float& Z() { return m_z; }

    // -----------------------------------------------------------------------
    /// \name Operators
    // -----------------------------------------------------------------------

    /// Compute the dot product of this vector and \p other.
    ///
    /// \param other The other vector.
    ///
    /// \return The dot product.
    float DotProduct(const Vec3f& other) const;

private:
    float m_x = 0.0f;
    float m_y = 0.0f;
    float m_z = 0.0f;
};

} // namespace cxxpythondocs
