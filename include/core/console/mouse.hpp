#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#ifndef BOX_MOUSE_HPP
#define BOX_MOUSE_HPP

class BOX_Mouse
{
    private:

        unsigned char mButtonState[GLFW_MOUSE_BUTTON_LAST + 1];
        unsigned int  mModBitField;

        float         mScrollOffset_x;
        float         mScrollOffset_y;
        float         mPos_x;
        float         mPos_y;
        float         mPos_dx;
        float         mPos_dy;

    public:

        BOX_Mouse();

        void Update();

        bool IsButtonPressed(int aButton);
        bool IsButtonHeld(int aButton);
        bool IsButtonReleased(int aButton);
        bool IsModPressed(int aMod);
        bool DidMouseScroll();

        float GetX()       { return mPos_x; }
        float GetY()       { return mPos_y; }
        float GetDX()      { return mPos_dx; }
        float GetDY()      { return mPos_dy; }
        float GetScrollX() { return mScrollOffset_x; }
        float GetScrollY() { return mScrollOffset_y; }

};

#endif
