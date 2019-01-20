#include <core/console/keyboard.hpp>

BOX_Keyboard::BOX_Keyboard():
    mModBitfield(0)
{

}

void BOX_Keyboard::Update()
{
    mPressed.clear();
    mReleased.clear();
    mModBitfield = 0;
}

bool BOX_Keyboard::IsKeyPressed(int aKey)
{
    return mPressed.find(aKey) != mPressed.end();
}

bool BOX_Keyboard::IsKeyHeld(int aKey)
{
    return mHeld.find(aKey) != mHeld.end();
}

bool BOX_Keyboard::IsKeyReleased(int aKey)
{
    return mReleased.find(aKey) != mReleased.end();
}

bool BOX_Keyboard::IsModPressed(int aMod)
{
    return mModBitfield & aMod;
}

void BOX_Keyboard::SetKeyState(int aKey, int aState)
{
    if (aState & KEY_PRESSED)  mPressed.insert(aKey);
    if (aState & KEY_HELD)     mHeld.insert(aKey);
    if (aState & KEY_RELEASED) mReleased.insert(aKey);
}

void BOX_Keyboard::SetModBitField(int aMods)
{
    mModBitfield = aMods;
}

void BOX_Keyboard::RemoveKeyState(int aKey, int aState)
{
    if (aState & KEY_HELD)     mHeld.erase(aKey);
    if (aState & KEY_PRESSED)  mPressed.erase(aKey);
    if (aState & KEY_RELEASED) mReleased.erase(aKey);
}