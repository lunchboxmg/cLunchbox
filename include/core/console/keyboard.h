#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#ifndef _BOX_keyboard_h_
#define _BOX_keyboard_h_
#endif

#define KEY_PRESSED  0x01
#define KEY_HELD     0x02
#define KEY_RELEASED 0x04

class BOX_Keyboard
{
    private:

        unsigned char mKeysStatus[1024];
        unsigned int mModBitfield;

    public:

        BOX_Keyboard();

        bool IsKeyPressed(int aKey);
        bool IsKeyHeld(int aKey);
        bool IsKeyReleased(int aKey);
        bool IsModPressed(int aMod);

        void SetKeyState(int aKey, unsigned char aState);

}