#include "Events.hpp"

PhysicsEvent::PhysicsEvent(EventType Type, Body *a, Body *b) : Type(Type), body1(a), body2(b) {}

