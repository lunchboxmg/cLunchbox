#include <iostream>
#include <fstream>

#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

//#include <core/console/console.h>
#include <core/console/window.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void processInput(GLFWwindow *window);

int main()
{

    BOX_Window window = BOX_Window(SCR_WIDTH, SCR_HEIGHT, "Test Window");
    int passed = window.CreateContext();
    if (passed < 0)
    {
        std::cout << "Window Context was not created correctly! (" << passed << ")" << std::endl;
        return passed;
    }

    // render loop
    // -----------
    float prevTime = 0.0;
    while (window.IsOpen())
    {
        // input
        // -----
        //processInput(window);
        processInput(window.GetContext());

        // render
        // ------
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        window.Swap();
        glfwPollEvents();

        double curTime = glfwGetTime();
        double dt = curTime - prevTime;
        prevTime = curTime;
        //std::cout << "FPS: " << 1/dt << std::endl;
    }
    window.Destroy();

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
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