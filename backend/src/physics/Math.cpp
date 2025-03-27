#include "Math.hpp"

// Defining vectors
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

// Defining points
Point3::Point3() : x(0), y(0), z(0) {}
Point3::Point3(double x, double y, double z) : x(x), y(y), z(z) {}
Point3 Point3::operator+(const Vec3 &other) const { return Point3(x + other.x, y + other.y, z + other.z); }
Point3 &Point3::operator+=(const Vec3 &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}
Vec3 Point3::operator-(const Point3 &other) const { return Vec3(x - other.x, y - other.y, z - other.z); }

// Utils
double PointDistanceSquared(const Point3 &p1, const Point3 &p2)
{
    double sx = p1.x - p2.x;
    double sy = p1.y - p2.y;
    double sz = p1.z - p2.z;
    return sx * sx + sy * sy + sz * sz;
}
