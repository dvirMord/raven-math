#include "Vector3D.hpp"
#include <cmath>
#include <stdexcept>

namespace RavenMaths
{
    Vector3D& Vector3D::operator/=(double scalar)
    {
        if (scalar == 0.0)
        {
            throw std::invalid_argument("Division by zero scalar.");
        }

        _x /= scalar;
        _y /= scalar;
        _z /= scalar;
        return *this;
    }

    Vector3D Vector3D::operator/(double scalar) const
    {
        Vector3D result = *this;
        result /= scalar;
        return result;
    }

    double Vector3D::length() const
    {
        return std::sqrt(lengthSquared());
    }

    Vector3D Vector3D::normalize() const
    {
        double len = length();

        if (len == 0.0)
        {
            throw std::runtime_error("Cannot normalize a zero vector.");
        }

        return *this / len; 
    }

    Vector3D Vector3D::cross(const Vector3D& a, const Vector3D& b)
    {
        return Vector3D(
            (a._y * b._z) - (a._z * b._y),
            (a._z * b._x) - (a._x * b._z),
            (a._x * b._y) - (a._y * b._x)
        );
    }

    std::string Vector3D::toString() const
    {
        return "Vector3D(" + std::to_string(_x) + ", " +
            std::to_string(_y) + ", " +
            std::to_string(_z) + ")";
    }

    std::ostream& operator<<(std::ostream& os, const Vector3D& vec)
    {
        os << vec.toString();
        return os;
    }
}