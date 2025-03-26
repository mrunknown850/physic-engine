#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "Math.hpp"

// Represents a physics object (e.g., a moving ball)
class Body
{
public:
    Point3 position;
    Vec3 velocity;
    bool IsFixed;
    float mass;

    Body(Point3 pos, float mass, Vec3 v = Vec3(0, 0, 0), bool IsFixed = false);
    // Body(Point3 pos, float mass);
};

#endif