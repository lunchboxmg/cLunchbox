#include <iostream>
#include <fstream>

#include "core/console/console.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void processInput(GLFWwindow *window);

int main()
{
    if (!BOX_Console::Instance().Initialize(SCR_WIDTH, SCR_HEIGHT, "Test Window"))
    {
        return -999;
    }
    BOX_Window window = BOX_Console::Instance().GetWindow();

    while (window.IsOpen())
    {
        processInput(window.GetContext());

        // render
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        window.Swap();
        BOX_Console::Instance().Update();
        glfwPollEvents();

        std::cout << "FPS: " << BOX_Console::Instance().GetClock().GetFps() << std::endl;
    }
    window.Destroy();

    glfwTerminate();
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