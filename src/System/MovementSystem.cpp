#include "MovementSystem.h"

void MovementSystem::Update() {
    float height = 600.0f;
    float width = 800.0f;
    for (auto& entity : entities) {
        // Retrieve the position component for the entity
        auto& position = componentManager.GetComponent<PositionComponent>(entity);
        auto& velocity = componentManager.GetComponent<VelocityComponent>(entity);

        // Update the position based on the speed
        position.x += (velocity.x * deltaTime);  // Move along the x-axis
        position.y += (velocity.y * deltaTime);  // Move along the y-axis

        if (position.x < 0 || position.x > width) {
            // position.x = 0;
            velocity.x = -velocity.x;
        }
        if (position.y < 0 || position.y > height) {
            // position.x = width;
            velocity.y = -velocity.y;
        }
    }
}