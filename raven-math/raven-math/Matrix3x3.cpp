#include "Matrix3x3.h"
#include <cmath>
#include <sstream>
#include <iomanip>

namespace RavenMaths
{
    Matrix3x3 Matrix3x3::identity()
    {
        Matrix3x3 result;
        result._m[0][0] = 1.0;
        result._m[1][1] = 1.0;
        result._m[2][2] = 1.0;
        return result;
    }

    Matrix3x3 Matrix3x3::operator*(const Matrix3x3& other) const
    {
        Matrix3x3 result;
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                result._m[row][col] =
                    _m[row][0] * other._m[0][col] +
                    _m[row][1] * other._m[1][col] +
                    _m[row][2] * other._m[2][col];
            }
        }
        return result;
    }

    Vector3D Matrix3x3::operator*(const Vector3D& vec) const
    {
        double x = _m[0][0] * vec.getX() + _m[0][1] * vec.getY() + _m[0][2] * vec.getZ();
        double y = _m[1][0] * vec.getX() + _m[1][1] * vec.getY() + _m[1][2] * vec.getZ();
        double z = _m[2][0] * vec.getX() + _m[2][1] * vec.getY() + _m[2][2] * vec.getZ();

        return Vector3D(x, y, z);
    }

    Matrix3x3 Matrix3x3::rotationX(double angleInRadians)
    {
        Matrix3x3 result;
        double c = std::cos(angleInRadians);
        double s = std::sin(angleInRadians);

        result._m[0][0] = 1.0;
        result._m[1][1] = c;
        result._m[1][2] = -s;
        result._m[2][1] = s;
        result._m[2][2] = c;

        return result;
    }

    Matrix3x3 Matrix3x3::rotationY(double angleInRadians)
    {
        Matrix3x3 result;
        double c = std::cos(angleInRadians);
        double s = std::sin(angleInRadians);

        result._m[0][0] = c;
        result._m[0][2] = s;
        result._m[1][1] = 1.0;
        result._m[2][0] = -s;
        result._m[2][2] = c;

        return result;
    }

    Matrix3x3 Matrix3x3::rotationZ(double angleInRadians)
    {
        Matrix3x3 result;
        double c = std::cos(angleInRadians);
        double s = std::sin(angleInRadians);

        result._m[0][0] = c;
        result._m[0][1] = -s;
        result._m[1][0] = s;
        result._m[1][1] = c;
        result._m[2][2] = 1.0;

        return result;
    }

    std::string Matrix3x3::toString() const
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(6);
        oss << "Matrix3x3[\r\n"
            << "  [" << _m[0][0] << ", " << _m[0][1] << ", " << _m[0][2] << "]\r\n"
            << "  [" << _m[1][0] << ", " << _m[1][1] << ", " << _m[1][2] << "]\r\n"
            << "  [" << _m[2][0] << ", " << _m[2][1] << ", " << _m[2][2] << "]\r\n"
            << "]";
        return oss.str();
    }

    std::ostream& operator<<(std::ostream& os, const Matrix3x3& mat)
    {
        os << mat.toString();
        return os;
    }
}