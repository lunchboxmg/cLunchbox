#ifndef BOX_KEYBOARD_HPP
#define BOX_KEYBOARD_HPP

#define KEY_PRESSED  0x01
#define KEY_HELD     0x02
#define KEY_RELEASED 0x04

class BOX_Keyboard
{
    private:

        unsigned char mKeyState[1024];
        unsigned int  mModBitfield;

    public:

        BOX_Keyboard();

        void Update();

        bool IsKeyPressed(int aKey);
        bool IsKeyHeld(int aKey);
        bool IsKeyReleased(int aKey);
        bool IsModPressed(int aMod);

        void SetKeyState(int aKey, unsigned char aState);
        void SetModBitField(int aMods);
        unsigned char GetKeyState(int aKey);

};

#endif
