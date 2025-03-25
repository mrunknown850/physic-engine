#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

#include "Math.hpp"

// Represents a physics object (e.g., a moving ball)
class RigidBody
{
public:
    Vec3 position;
    Vec3 velocity;
    float mass;

    RigidBody(Vec3 pos, float mass);
};

#endif