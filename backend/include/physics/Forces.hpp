#ifndef FORCE_HPP
#define FORCE_HPP

#include "Math.hpp"

// Implementation of basic force.
class Force
{
public:
    Vec3 origin;
    Vec3 pointing_vector;
    float duration;

    Force(Vec3 origin, Vec3 pointing_vector, float duration);
    Force operator+(const Force &other) const;
    Force operator-(const Force &other) const;
    Force operator*(float scalar) const;
    Force &operator+=(const Force &other);
};

#endif