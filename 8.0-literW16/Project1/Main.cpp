#include "OBJLoader.h"

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        return -1;
    }

    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "8.0-literW16", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    OBJLoader test("Assets\\Test.obj");
    
    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Main game loop
    while (!glfwWindowShouldClose(window))
    {
        // Input handling
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
      
        // Draw a triangle
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glEnd();
        // Rendering code goes here

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Clean up
    glfwTerminate();

    return 0;
}