#pragma once

#include "Vector3D.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

namespace RavenMaths
{
    class Matrix3x3
    {
    private:
        double _m[3][3];

    public:
        Matrix3x3() : _m{ {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0} } {}
        ~Matrix3x3() = default;

        double operator()(int row, int col) const {
            if (row < 0 || row >= 3 || col < 0 || col >= 3) {
                throw std::out_of_range("Matrix index out of bounds.");
            }
            return _m[row][col];
        }

        double& operator()(int row, int col) {
            if (row < 0 || row >= 3 || col < 0 || col >= 3) {
                throw std::out_of_range("Matrix index out of bounds.");
            }
            return _m[row][col];
        }
        static Matrix3x3 identity();
        Matrix3x3 operator*(const Matrix3x3& other) const;

        Vector3D operator*(const Vector3D& vec) const;

        static Matrix3x3 rotationX(double angleInRadians);
        static Matrix3x3 rotationY(double angleInRadians);
        static Matrix3x3 rotationZ(double angleInRadians);

        std::string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Matrix3x3& mat);
    };
}