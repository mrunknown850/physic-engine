#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "configs.hpp"
#include "Math.hpp"
#include "Forces.hpp"
#include "RigidBody.hpp"

#include <vector>
#include <unordered_map>

// Handles the physics simulation, literally mastermind
class PhysicsEngine
{
private:
    std::vector<RigidBody> bodies;
    std::unordered_map<int, std::vector<Force>> forces;
    double timeStep;

public:
    PhysicsEngine(double timeStep = 1.0 / FRAME_PER_SECOND); // Default: 60 FPS

    // Getting informations
    RigidBody *GetObject(int body_id);
    int CreateObject(const RigidBody &body);
    int ObjectCount();

    // Applying forces
    void applyForce(int bodyIndex, const Force &force);
    void update();
    // std::vector<RigidBody> getState() const;
};

#endif // PHYSICS_HPP
