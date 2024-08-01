#pragma once

#include "System.h"
#include "ComponentManager.h"
#include "PositionComponent.h"
#include "RenderComponent.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class RenderSystem : public System {
public:
    RenderSystem(ComponentManager& componentManager)
        : componentManager{componentManager}, window{nullptr} {
            Initialize();
        }

    ~RenderSystem() {
        Shutdown();
    }

    void Initialize();
    void Update() override;
    void Shutdown();

    inline bool ShouldClose() {
        return glfwWindowShouldClose(window);
    }

private:
    ComponentManager& componentManager;
    GLFWwindow* window;
};
