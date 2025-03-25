#ifndef MATH_HPP
#define MATH_HPP

class Vec3
{
public:
    double x, y, z;

    Vec3();
    Vec3(double x, double y, double z);

    Vec3 operator+(const Vec3 &other) const;    // Vectors addition
    Vec3 operator-(const Vec3 &other) const;    // Vectors subtraction
    double operator*(const Vec3 &other) const;     // Vector dot product
    Vec3 operator*(double scalar) const;     // Vector scaling
    Vec3 &operator+=(const Vec3 &other);    // Shorthand addition
    
    double LengthSquared() const;
};

#endif