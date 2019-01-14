#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#include <core/console/keyboard.h>

class BOX_Keyboard;

BOX_Keyboard gKeyboard;

static void KeyCallback(GLFWwindow* aWindow, int aKey, int aScancode, int aAction, int aMods)
{
    if (0 <= aKey && aKey <= 1024)
    {
        if (aAction == GLFW_PRESS)
        {
            if (!gKeyboard.IsKeyPressed(aKey))
            {
                gKeyboard.SetKeyState(aKey, KEY_PRESSED | KEY_HELD);
            }
        }
        if (aAction == GLFW_RELEASE)
        {

        }
    }
}

