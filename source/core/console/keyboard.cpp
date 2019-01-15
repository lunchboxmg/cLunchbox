#include <iostream>

#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#include <core/console/keyboard.h>

class BOX_Keyboard;

extern BOX_Keyboard* gKeyboard;

static void KeyCallback(GLFWwindow* aWindow, int aKey, int aScancode, int aAction, int aMods)
{
    if (0 <= aKey && aKey <= 1024)
    {
        if (aAction == GLFW_PRESS)
        {
            if (!gKeyboard->IsKeyPressed(aKey))
            {
                gKeyboard->SetKeyState(aKey, KEY_PRESSED | KEY_HELD);
            }
        }
        if (aAction == GLFW_RELEASE)
        {
            unsigned char state = gKeyboard->GetKeyState(aKey);
            gKeyboard->SetKeyState(aKey, state ^ KEY_HELD | KEY_RELEASED);
        }
        gKeyboard->SetModBitField(aMods);
        std::cout << aKey << "\t" << aAction << "\t" << aMods << std::endl;
    }
}

BOX_Keyboard::BOX_Keyboard(GLFWwindow* aWindow)
{
    mKeyState[1024] = {0};
    mModBitfield = 0;
    glfwSetKeyCallback(aWindow, KeyCallback);
}

bool BOX_Keyboard::IsKeyPressed(int aKey)
{
    return mKeyState[aKey] & KEY_PRESSED;
}

bool BOX_Keyboard::IsKeyHeld(int aKey)
{
    return mKeyState[aKey] & KEY_HELD;
}

bool BOX_Keyboard::IsKeyReleased(int aKey)
{
    return mKeyState[aKey] & KEY_RELEASED;
}

bool BOX_Keyboard::IsModPressed(int aMod)
{
    return mModBitfield & aMod;
}

void BOX_Keyboard::SetKeyState(int aKey, unsigned char aState)
{
    mKeyState[aKey] = aState;
}

void BOX_Keyboard::SetModBitField(int aMods)
{
    mModBitfield = aMods;
}

unsigned char BOX_Keyboard::GetKeyState(int aKey)
{
    return mKeyState[aKey];
}