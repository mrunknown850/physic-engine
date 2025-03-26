#include "PhysicsEngine.hpp"

// Implement physic engine
PhysicsEngine::PhysicsEngine(double timeStep) : timeStep(timeStep) {}
int PhysicsEngine::ObjectCount() { return bodies.size(); }
int PhysicsEngine::CreateObject(const Body &body)
{
    bodies.push_back(body);
    return bodies.size() - 1;
}
void PhysicsEngine::applyForce(int bodyIndex, const Force &force)
{
    if (bodyIndex < 0 || bodyIndex >= bodies.size())
        return;
    forces[bodyIndex].push_back(force);
}

// Get Object
Body *PhysicsEngine::GetObject(int body_id) { return &bodies[body_id]; }

// Implement physic update
void PhysicsEngine::update()
{
    for (size_t i = 0; i < bodies.size(); i++)
    {
        if (forces.find(i) == forces.end())
            continue;
        Vec3 net_force(0, 0, 0);
        for (Force &force : forces[i])
        {
            net_force += force.pointing_vector;
            force.duration -= timeStep;
        }

        if (bodies[i].mass > 0)
        {
            Vec3 accel = net_force * (1.0f / bodies[i].mass); // F = ma (1st Newton)
            bodies[i].velocity += accel * timeStep;           // v = v0 + a*t
        }

        bodies[i].position += bodies[i].velocity * timeStep;
    }
}
