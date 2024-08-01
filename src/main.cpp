#include <iostream>
#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include "PositionComponent.h"
#include "VelocityComponent.h"
#include "MovementSystem.h"
#include "RenderSystem.h"

int main() {
    // Create managers
    ComponentManager componentManager;
    EntityManager entityManager;
    SystemManager systemManager;

    // Register components
    componentManager.RegisterComponent<PositionComponent>();
    componentManager.RegisterComponent<RenderComponent>();
    componentManager.RegisterComponent<VelocityComponent>();

    // Create and register the movement system
    auto movementSystem = systemManager.RegisterSystem<MovementSystem>(componentManager, 0.1f); // Speed of 0.1f
    systemManager.SetSignature<MovementSystem>(Signature().set(componentManager.GetComponentType<PositionComponent>())
                                                            .set(componentManager.GetComponentType<VelocityComponent>()));

    // Create an entity and add a PositionComponent
    Entity entity = entityManager.CreateEntity();
    componentManager.AddComponent(entity, PositionComponent{0.0f, 0.0f});
    componentManager.AddComponent(entity, VelocityComponent{5.0f, 5.0f});
    componentManager.AddComponent(entity, RenderComponent{0.f, 0.f, 1.0f, 20.0f, 20.0f});
    movementSystem->entities.insert(entity);

    auto renderSystem = systemManager.RegisterSystem<RenderSystem>(componentManager); // Speed of 0.1f
    systemManager.SetSignature<MovementSystem>(Signature().set(componentManager.GetComponentType<PositionComponent>())
                                                            .set(componentManager.GetComponentType<RenderComponent>()));

    renderSystem->entities.insert(entity);

    while(!renderSystem->ShouldClose()) {
        movementSystem->Update();
        renderSystem->Update();
    }

    return 0;
}