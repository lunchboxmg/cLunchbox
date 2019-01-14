#include <iostream>

#include <core/console/console.h>

Console::Console(unsigned int aWidth, unsigned int aHeight, const char* aTitle)
{
    // Initialize and configure GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
   
    // Create the GFLW Window
    mAspect = (float)mWidth/(float)mHeight;
    GLFWwindow* temp = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (temp == NULL);
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-10);
    }
    mWindow = temp;
    glfwMakeContextCurrent(mWindow);
    //glfwSetFramebufferSizeCallback(mWindow, WindowResizeCallback);
    glViewport(0, 0, mWidth, mHeight);

    // load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        exit(-20);
    }


}