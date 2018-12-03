#include <iostream>
#include "glew.h"
#include "glfw3.h"

int main() {
    GLFWwindow* window;

    // Initialize glfw
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    // Create a window with an OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        std::cout << "Could not create a GLFW window!" << std::endl;
        return -1;
    }

    // Make the window's context the current OpenGL context
    glfwMakeContextCurrent(window);

    if (!glewInit())
    {
        std::cout << "Failed to initialize GLEW!" << std::endl;
        return -1;
    }

    // Draw Call Loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear screen
        glClear(GL_COLOR_BUFFER_BIT);

    }

    return 0;
}