#include "RenderSystem.h"

void RenderSystem::Initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    window = glfwCreateWindow(800, 600, "OpenGL Window", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return;
    }

    // Set up orthographic projection
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    std::cout << "OpenGL initialized" << std::endl;
}

void RenderSystem::Update() {
    if (!window) return;
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto& entity : entities) {
        auto& position =
            componentManager.GetComponent<PositionComponent>(entity);
        auto& render = componentManager.GetComponent<RenderComponent>(entity);

        // Calculate the corners of the rectangle around the center position
        float left = position.x - render.width / 2.0f;
        float right = position.x + render.width / 2.0f;
        float bottom = position.y - render.height / 2.0f;
        float top = position.y + render.height / 2.0f;

        // Render the entity as a colored rectangle
        glColor3f(render.r, render.g, render.b);
        glBegin(GL_QUADS);
        glVertex2f(left, bottom);
        glVertex2f(right, bottom);
        glVertex2f(right, top);
        glVertex2f(left, top);
        glEnd();
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void RenderSystem::Shutdown() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}