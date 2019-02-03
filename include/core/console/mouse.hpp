#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#ifndef BOX_MOUSE_HPP
#define BOX_MOUSE_HPP

#define BUTTON_PRESSED  0x01
#define BUTTON_HELD     0x02
#define BUTTON_RELEASED 0x04
#define NUM_BUTTONS     GLFW_MOUSE_BUTTON_LAST + 1

#define NO_CURSOR_VALUE -9e9

class BOX_Mouse
{
    private:

        unsigned char mButtonState[NUM_BUTTONS];
        unsigned int  mModBitField;

        float         mScrollOffset_x;
        float         mScrollOffset_y;
        float         mPos_x;
        float         mPos_y;
        float         mPos_dx;
        float         mPos_dy;

        GLFWwindow*   mContext;

    public:

        BOX_Mouse();
        BOX_Mouse(GLFWwindow* aContext);

        void Update();

        bool IsButtonPressed(int aButton);
        bool IsButtonHeld(int aButton);
        bool IsButtonReleased(int aButton);
        bool IsModPressed(int aMod);
        bool DidMouseScroll();

        void          SetButtonState(int aButton, unsigned char aState);
        unsigned char GetButtonState(int aButton);
        void          SetModBitField(int aMods);
        void          HandleScroll(double aOffset_x, double aOffset_y);

        void SetContext(GLFWwindow* aContext);

        float GetX()       { return mPos_x; }
        float GetY()       { return mPos_y; }
        float GetDX()      { return mPos_dx; }
        float GetDY()      { return mPos_dy; }
        float GetScrollX() { return mScrollOffset_x; }
        float GetScrollY() { return mScrollOffset_y; }

};

#endif
