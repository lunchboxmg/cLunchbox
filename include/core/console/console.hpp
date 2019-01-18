#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#include <core/console/window.hpp>
#include <core/console/keyboard.hpp>

#ifndef BOX_CONSOLE_HPP
#define BOX_CONSOLE_HPP

class BOX_Console
{
    private:

        BOX_Window   mWindow;
        BOX_Keyboard mKeyboard;
        bool         mInitialized;

        BOX_Console();
        BOX_Console(BOX_Console const&);
        BOX_Console& operator= (BOX_Console const&);
        ~BOX_Console();

    public:

        static BOX_Console& Instance() { static BOX_Console console; return console; }

        bool Initialize(unsigned int, unsigned int, const char*);

        BOX_Window   GetWindow()   { return mWindow; }
        BOX_Keyboard GetKeyboard() { return mKeyboard; }
        GLFWwindow*  GetContext()  { return mWindow.GetContext(); }

};

static void KeyCallback(GLFWwindow* aWindow, int aKey, int aScancode, int aAction, int aMods);

#endif
