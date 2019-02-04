#include <iostream>
#include <fstream>

#include <core/windowz.hpp>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void processInput(GLFWwindow *window);

int main()
{
    int success = WindowZ::Initialize(SCR_WIDTH, SCR_HEIGHT, "Test Window");
    if (success < 1) { return success; }

    while (WindowZ::IsOpen())
    {
        WindowZ::Update();
        processInput(WindowZ::GetContext());

        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        WindowZ::SwapBuffers();
    }
    WindowZ::Destroy();

    return 9;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}