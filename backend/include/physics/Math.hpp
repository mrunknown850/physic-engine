#ifndef MATH_HPP
#define MATH_HPP

class Vec3
{
public:
    float x, y, z;

    Vec3();
    Vec3(float x, float y, float z);

    Vec3 operator+(const Vec3 &other) const;
    Vec3 operator-(const Vec3 &other) const;
    Vec3 operator*(float scalar) const;
    Vec3 &operator+=(const Vec3 &other);
};

#endif