#include <iostream>

#include <core/console/mouse.hpp>

BOX_Mouse::BOX_Mouse():
    mModBitField(0),
    mPos_x(0),
    mPos_y(0),
    mPos_dx(0),
    mPos_dy(0),
    mScrollOffset_x(0),
    mScrollOffset_y(0),
    mContext(nullptr)
{
    mButtonState[NUM_BUTTONS] = {0};
}

BOX_Mouse::BOX_Mouse(GLFWwindow* aContext):
    mModBitField(0),
    mPos_x(0),
    mPos_y(0),
    mPos_dx(0),
    mPos_dy(0),
    mScrollOffset_x(0),
    mScrollOffset_y(0),
    mContext(aContext)
{
    mButtonState[NUM_BUTTONS] = {0};
}

void BOX_Mouse::Update()
{

    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        if (mButtonState[i] > 0)
        {
            mButtonState[i] = mButtonState[i] ^ BUTTON_PRESSED ^ BUTTON_RELEASED;
        }
    }

    double cur_x = NO_CURSOR_VALUE;
    double cur_y = NO_CURSOR_VALUE;
    if (mContext == nullptr)
    {
        std::cout << "OH SHIT!";
    }
    glfwGetCursorPos(mContext, &cur_x, &cur_y);
    if ((cur_x == NO_CURSOR_VALUE) || (cur_y == NO_CURSOR_VALUE))
    {
        std::cout << "Cursor Error" << std::endl;
    }

    mPos_dx = cur_x - mPos_x;
    mPos_dy = cur_y - mPos_y;
    mPos_x = cur_x;
    mPos_y = cur_y;

    mScrollOffset_x = 0;
    mScrollOffset_y = 0;
}

bool BOX_Mouse::IsButtonPressed(int aButton)
{
    return mButtonState[aButton] & BUTTON_PRESSED;
}

bool BOX_Mouse::IsButtonHeld(int aButton)
{
    return mButtonState[aButton] & BUTTON_HELD;
}

bool BOX_Mouse::IsButtonReleased(int aButton)
{
    return mButtonState[aButton] & BUTTON_RELEASED;
}

bool BOX_Mouse::IsModPressed(int aMod)
{
    return mModBitField & aMod;
}

bool BOX_Mouse::DidMouseScroll()
{
    return (mPos_dx != 0.0) || (mPos_dy != 0.0);
}

void BOX_Mouse::SetButtonState(int aButton, unsigned char aState)
{
    mButtonState[aButton] = aState;
}

unsigned char BOX_Mouse::GetButtonState(int aButton)
{
    return mButtonState[aButton];
}

void BOX_Mouse::SetModBitField(int aMods)
{
    mModBitField = aMods;
}

void BOX_Mouse::HandleScroll(double aOffset_x, double aOffset_y)
{
    mScrollOffset_x = aOffset_x;
    mScrollOffset_y = aOffset_y;
}

void BOX_Mouse::SetContext(GLFWwindow* aContext)
{
    if (aContext == nullptr)
    {
        std::cout << "ERROR: Window Context can be set on the mouse!" << std::endl;
    }
    else
    {
        mContext = aContext;
    }
}