#include <iostream>

#include <core/console/window.hpp>

void WindowResizeCallback(GLFWwindow* window, int width, int height);

BOX_Window::BOX_Window():
    mWidth(0),
    mHeight(0),
    mAspect(0),
    mWindow(NULL),
    mCloseRequested(false)
{
    ;
}

BOX_Window::BOX_Window(unsigned int aWidth, unsigned int aHeight, const char* aTitle):
    mWidth(aWidth),
    mHeight(aHeight),
    mAspect(0),
    mWindow(NULL),
    mCloseRequested(false)
{
    mAspect = (float)mWidth/(float)mHeight;
}

int BOX_Window::CreateContext()
{
    // Initialize and configure GLFW
    if (!glfwInit())
    {
        std::cout << "GLFW did not initialize properly!" << std::endl;
        return -999;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif
   
    // Create the GFLW Window
    // --------------------
    mWindow = glfwCreateWindow(mWidth, mHeight, "LearnOpenGL", NULL, NULL);
    if (mWindow == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -10;
    }
    glfwMakeContextCurrent(mWindow);
    glfwSetFramebufferSizeCallback(mWindow, WindowResizeCallback);

    // load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -20;
    }

    return 1;
}

int BOX_Window::CreateContext(unsigned int aWidth, unsigned int aHeight, const char* aTitle)
{
    mWidth = aWidth;
    mHeight = aHeight;
    return CreateContext();
}

void BOX_Window::SetDimensions(unsigned int aWidth, unsigned int aHeight)
{
    mWidth = aWidth;
    mHeight = aHeight;
    mAspect = (float)aWidth/(float)aHeight;

    WindowResizeCallback(mWindow, mWidth, mHeight);
}

void BOX_Window::Swap()
{
    glfwSwapBuffers(mWindow);
}

void BOX_Window::Close()
{
    glfwSetWindowShouldClose(mWindow, GL_TRUE);
}

void BOX_Window::RequestClose()
{
    mCloseRequested = true;
}

bool BOX_Window::IsCloseRequested()
{
    return mCloseRequested;
}

bool BOX_Window::IsOpen()
{
    return !glfwWindowShouldClose(mWindow); // && !mCloseRequested;
}

void BOX_Window::Destroy()
{
    glfwDestroyWindow(mWindow);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void WindowResizeCallback(GLFWwindow* aWindow, int aWidth, int aHeight)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    std::cout << "RESIZE" << std::endl;
    glViewport(0, 0, aWidth, aHeight);
}
