#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <unordered_map>
#include <vector>
#include <functional>
#include "RigidBody.hpp"

enum class EventType
{
    Collision,
    Force
};

class PhysicsEvent
{
public:
    EventType Type;
    Body *body1, *body2;
    PhysicsEvent(EventType Type, Body *a, Body *b = nullptr);
};

class IEventListener
{
public:
    virtual void OnEvent(const PhysicsEvent &event) = 0;
    virtual ~IEventListener() = default;
};

class EventManager
{
private:
    std::unordered_map<EventType, std::vector<IEventListener *>> listeners;

public:
    void RegisterListener(EventType type, IEventListener *listener)
    {
        listeners[type].push_back(listener);
    }
    void DispatchEvent(const PhysicsEvent &event)
    {
        if (listeners.find(event.Type) != listeners.end())
        {
            for (IEventListener *listener : listeners[event.Type])
            {
                listener->OnEvent(event);
            }
        }
    }
};

#endif