#pragma once

#include <string>
#include <iostream>

namespace RavenMaths
{
    class Vector3D
    {
    private:
        double _x;
        double _y;
        double _z;

    public:
        // Constructors (Implicitly inline)
        Vector3D() : _x(0.0), _y(0.0), _z(0.0) {}
        Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}
        ~Vector3D() = default;

        // Getters & Setters (Implicitly inline)
        double getX() const { return _x; }
        double getY() const { return _y; }
        double getZ() const { return _z; }

        void setX(double x) { _x = x; }
        void setY(double y) { _y = y; }
        void setZ(double z) { _z = z; }

        // Assignment arithmetic operators (In-place)
        Vector3D& operator+=(const Vector3D& rhs) {
            _x += rhs._x; _y += rhs._y; _z += rhs._z;
            return *this;
        }

        Vector3D& operator-=(const Vector3D& rhs) {
            _x -= rhs._x; _y -= rhs._y; _z -= rhs._z;
            return *this;
        }

        Vector3D& operator*=(double scalar) {
            _x *= scalar; _y *= scalar; _z *= scalar;
            return *this;
        }

        // Division is left in the .cpp file because it contains validation logic (throw)
        Vector3D& operator/=(double scalar);

        // Unary negation (-Vector)
        Vector3D operator-() const { return Vector3D(-_x, -_y, -_z); }

        // Binary arithmetic operators
        Vector3D operator+(const Vector3D& rhs) const {
            return Vector3D(_x + rhs._x, _y + rhs._y, _z + rhs._z);
        }

        Vector3D operator-(const Vector3D& rhs) const {
            return Vector3D(_x - rhs._x, _y - rhs._y, _z - rhs._z);
        }

        Vector3D operator*(double scalar) const {
            return Vector3D(_x * scalar, _y * scalar, _z * scalar);
        }

        Vector3D operator/(double scalar) const;

        // Scalar * Vector (friend operator)
        friend Vector3D operator*(double scalar, const Vector3D& vec) {
            return vec * scalar;
        }

        // Math methods
        double lengthSquared() const {
            return (_x * _x) + (_y * _y) + (_z * _z);
        }

        double length() const;
        Vector3D normalize() const;

        static double dot(const Vector3D& a, const Vector3D& b) {
            return (a._x * b._x) + (a._y * b._y) + (a._z * b._z);
        }

        static Vector3D cross(const Vector3D& a, const Vector3D& b);

        // Print the vector 
        std::string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec);
    };
}