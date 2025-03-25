#include "Math.hpp"

Vec3::Vec3() : x(0), y(0), z(0) {}
Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
Vec3 Vec3::operator+(const Vec3 &other) const { return Vec3(x + other.x, y + other.y, z + other.z); }
Vec3 Vec3::operator-(const Vec3 &other) const { return Vec3(x - other.x, y - other.y, z - other.z); }
Vec3 Vec3::operator*(const double scalar) const { return Vec3(x * scalar, y * scalar, z * scalar); }
Vec3 &Vec3::operator+=(const Vec3 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}
double Vec3::operator*(const Vec3 &other) const
{
    return x * other.x + y * other.y + z * other.z;
}
double Vec3::LengthSquared() const
{
    return x * x + y * y + z * z;
}