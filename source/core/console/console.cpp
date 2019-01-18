#include <iostream>

#include <core/console/console.hpp>
#include <core/console/window.hpp>
#include <core/console/keyboard.hpp>

BOX_Console::BOX_Console():
    mWindow(BOX_Window()),
    mKeyboard(BOX_Keyboard()),
    mInitialized(false)
{
    
}

BOX_Console::~BOX_Console()
{

}

bool BOX_Console::Initialize(unsigned int aWidth, unsigned int aHeight, const char* aTitle)
{
    // Create the Window context
    int result = mWindow.CreateContext(aWidth, aHeight, aTitle);
    if (result < 0)
    {
        return false;
    }

    // Set GLFW callbacks
    GLFWwindow* window = mWindow.GetContext();
    glfwSetKeyCallback(window, KeyCallback);

    mInitialized = true;
    return true;
}

static void KeyCallback(GLFWwindow* aWindow, int aKey, int aScancode, int aAction, int aMods)
{
    static BOX_Keyboard __keyboard = BOX_Console::Instance().GetKeyboard();

    if (0 <= aKey && aKey <= 1024)
    {
        if (aAction == GLFW_PRESS)
        {
            if (!__keyboard.IsKeyPressed(aKey))
            {
                __keyboard.SetKeyState(aKey, KEY_PRESSED | KEY_HELD);
            }
        }
        if (aAction == GLFW_RELEASE)
        {
            unsigned char state = __keyboard.GetKeyState(aKey);
            __keyboard.SetKeyState(aKey, state ^ KEY_HELD | KEY_RELEASED);
        }
        __keyboard.SetModBitField(aMods);
        std::cout << aKey << "\t" << aAction << "\t" << aMods << std::endl;
    }
}

