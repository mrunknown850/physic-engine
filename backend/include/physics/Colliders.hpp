#ifndef COLLIDERS_HPP
#define COLLIDERS_HPP

#include "Math.hpp"
#include "Base.hpp"

/**
 * @enum ColliderType
 * @brief Possible collider types
 */
enum class ColliderType
{
    CIRCLE,
    RECTANGLE
};

/**
 * @class Collider
 * @brief Define basis for colliders
 */
class Collider : public Component
{
public:
    Vec3 offset;

    /**
     * @brief Get absolute coordinate relative to global.
     */
    Point3 GetAbsoluteCenter() const;

    Collider(Object *parent, Vec3 offset = Vec3(0, 0, 0));

    virtual ColliderType GetType() const = 0;
    virtual bool CollidesWith(const Collider &other) const = 0;
};

/**
 * @class Circle Collider.
 * @brief Subtype of Collider, specifically for spheres.
 */
class SphereCollider : public Collider
{
public:
    double radius;

    /**
     * @brief Define a sphere collider.
     * @param parent Pointer point to the object with this collider.
     * @param center The center.
     * @param radius The radius.
     */
    SphereCollider(Object *parent, double radius, Vec3 offset = Vec3(0, 0, 0));

    /**
     * @brief Retrieving the type of collider.
     * @return CIRCLE
     */
    ColliderType GetType() const override { return ColliderType::CIRCLE; }

    /**
     * @brief Check if colliding with another collider.
     * @return Boolean.
     */
    bool CollidesWith(const Collider &other) const override;
};

/**
 * @class BoxCollider
 * @brief Subtype of Collider, specifically for boxes.
 */
class BoxCollider : public Collider
{
public:
    Point3 min() const { return GetAbsoluteCenter() + (scale * -1); }
    Point3 max() const { return GetAbsoluteCenter() + scale; }
    
    Vec3 scale;

    /**
     * @brief Construtor for BoxCollider
     * @param parent Pointer to object with this collider
     * @param scale The scale of the collider.
     * @param offset The position of the center of the collider relative to the object center.
     */
    BoxCollider(Object *parent, Vec3 scale, Vec3 offset = Vec3(0, 0, 0));

    /**
     * @brief Get the type of the collider
     * @return RECTANGLE
     */
    ColliderType GetType() const override { return ColliderType::RECTANGLE; }

    /**
     * @brief Check if colliding with another collider.
     * @return Boolean.
     */
    bool CollidesWith(const Collider &other) const override;
};

#endif