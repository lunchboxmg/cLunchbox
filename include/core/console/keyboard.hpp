#ifndef BOX_KEYBOARD_HPP
#define BOX_KEYBOARD_HPP

#include <unordered_set>
typedef std::unordered_set<int> state_set;

#define KEY_PRESSED  0x01
#define KEY_HELD     0x02
#define KEY_RELEASED 0x04

class BOX_Keyboard
{
    private:

        state_set mPressed;
        state_set mHeld;
        state_set mReleased;
        unsigned int  mModBitfield;

    public:

        BOX_Keyboard();

        void Update();

        bool IsKeyPressed(int aKey);
        bool IsKeyHeld(int aKey);
        bool IsKeyReleased(int aKey);
        bool IsModPressed(int aMod);

        void SetKeyState(int aKey, int aState);
        void SetModBitField(int aMods);
        void RemoveKeyState(int aKey, int aState);

};

#endif
