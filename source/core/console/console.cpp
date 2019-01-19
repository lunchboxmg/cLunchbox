#include <iostream>

#include <core/console/console.hpp>
#include <core/console/window.hpp>
#include <core/console/keyboard.hpp>

BOX_Console::BOX_Console():
    mWindow(BOX_Window()),
    mKeyboard(BOX_Keyboard()),
    mInitialized(false)
{
    mMouse = BOX_Mouse(mWindow.GetContext());
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
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetScrollCallback(window, ScrollCallback);

    mInitialized = true;
    return true;
}

void BOX_Console::Update()
{
    mKeyboard.Update();
    mMouse.Update();
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

static void MouseButtonCallback(GLFWwindow* aWindow, int aButton, int aAction, int aMods)
{
    static BOX_Mouse __mouse = BOX_Console::Instance().GetMouse();

    if ((0 <= aButton) && (aButton < NUM_BUTTONS))
    {
        if (aAction == GLFW_PRESS)
        {
            if (!__mouse.IsButtonHeld(aButton))
            {
                __mouse.SetButtonState(aButton, BUTTON_PRESSED | BUTTON_HELD);
            }
        }
        if (aAction == GLFW_RELEASE)
        {
            unsigned char state = __mouse.GetButtonState(aButton);
            __mouse.SetButtonState(aButton, state ^ BUTTON_HELD | BUTTON_RELEASED);
        }
        __mouse.SetModBitField(aMods);
    }
}

static void ScrollCallback(GLFWwindow* aWindow, double aOffset_x, double aOffset_y)
{
    static BOX_Mouse __mouse = BOX_Console::Instance().GetMouse();
    __mouse.HandleScroll(aOffset_x, aOffset_y);
}
