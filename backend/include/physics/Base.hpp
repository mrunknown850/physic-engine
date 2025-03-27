#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "RigidBody.hpp"

/**
 * @class Base component
 * @brief A base component class for classes that can be applied to bodies.
 */
class Component
{
protected:
    Body *parentObject;

public:
    Component(Body *parent = nullptr) : parentObject(parent) {}

    // Getter for the parent object
    Body *GetParent() const { return parentObject; }

    // Virtual destructor to allow proper cleanup in derived classes
    virtual ~Component() = default;
};

#endif