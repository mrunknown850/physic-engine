#include "Colliders.hpp"
#include "Math.hpp"
#include <algorithm>

// Forward declaration of IsCircleCircleCollision
Collider::Collider(Body *parent, Vec3 offset) : Component(parent), offset(offset) {}
Point3 Collider::GetAbsoluteCenter() const { return parentObject->position + offset; }

bool IsCircleCircleCollision(const SphereCollider &c1, const SphereCollider &c2)
{
    double centerDistance = PointDistanceSquared(c1.GetAbsoluteCenter(), c2.GetAbsoluteCenter());
    double radiusSum = c1.radius + c2.radius;
    return centerDistance <= radiusSum * radiusSum;
}

bool IsBoxBoxCollision(const BoxCollider &box1, const BoxCollider &box2)
{
    return (box1.min().x <= box2.max().x && box1.max().x >= box2.min().x) &&
           (box1.min().y <= box2.max().y && box1.max().y >= box2.min().y) &&
           (box1.min().z <= box2.max().z && box1.max().z >= box2.min().z);
}

bool IsSphereBoxCollision(const SphereCollider &sphere, const BoxCollider &box)
{
    // Find the closest point on the box to the sphere center
    Point3 closestPoint = {
        std::max(box.min().x, std::min(sphere.GetAbsoluteCenter().x, box.max().x)),
        std::max(box.min().y, std::min(sphere.GetAbsoluteCenter().y, box.max().y)),
        std::max(box.min().z, std::min(sphere.GetAbsoluteCenter().z, box.max().z))};

    // Compute squared distance from sphere center to closest point
    double distSquared = (closestPoint - sphere.GetAbsoluteCenter()).LengthSquared();

    // If distance squared is less than the squared radius, we have a collision
    return distSquared <= (sphere.radius * sphere.radius);
}

SphereCollider::SphereCollider(Body *parent, double r, Vec3 offset)
    : Collider(parent, offset), radius(r) {}
BoxCollider::BoxCollider(Body *parent, Vec3 scale, Vec3 offset)
    : Collider(parent, offset), scale(scale) {}
bool SphereCollider::CollidesWith(const Collider &other) const
{
    if (other.GetType() == ColliderType::CIRCLE)
    {
        return IsCircleCircleCollision(*this, static_cast<const SphereCollider &>(other));
    }
    if (other.GetType() == ColliderType::RECTANGLE)
    {
        return IsSphereBoxCollision(*this, static_cast<const BoxCollider &>(other));
    }
    return false;
}
bool BoxCollider::CollidesWith(const Collider &other) const
{
    if (other.GetType() == ColliderType::CIRCLE)
    {
        return IsSphereBoxCollision(static_cast<const SphereCollider &>(other), *this);
    }
    if (other.GetType() == ColliderType::RECTANGLE)
    {
        return IsBoxBoxCollision(*this, static_cast<const BoxCollider &>(other));
    }
    return false;
}

