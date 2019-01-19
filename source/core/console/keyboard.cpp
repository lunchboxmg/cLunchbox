#include <core/console/keyboard.hpp>

BOX_Keyboard::BOX_Keyboard()
{
    mKeyState[1024] = {0};
    mModBitfield = 0;
}

void BOX_Keyboard::Update()
{

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