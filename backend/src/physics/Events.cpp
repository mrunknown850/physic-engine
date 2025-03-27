#include "Events.hpp"

PhysicsEvent::PhysicsEvent(EventType Type, Object *a, Object *b) : Type(Type), body1(a), body2(b) {}

