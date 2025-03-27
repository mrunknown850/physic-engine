#include "RigidBody.hpp"

Object::Object(Point3 pos, float m, Vec3 v, bool fixed) : position(pos), mass(m), velocity(v), IsFixed(fixed) {}
// Body::Body(Point3 pos, float m) : position(pos), mass(m) {}
