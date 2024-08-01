#pragma once

#include "System.h"
#include "ComponentManager.h"
#include "VelocityComponent.h"
#include "PositionComponent.h"

class MovementSystem : public System {
public:
    MovementSystem(ComponentManager& componentManager, float inDeltaTime)
        : componentManager{componentManager}, deltaTime{inDeltaTime} {}

    virtual void Update() override;

private:
    ComponentManager& componentManager;
    float deltaTime;
};
