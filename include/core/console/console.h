#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

//#include <core/console/box_window.h>

#ifndef console_h
#define console_h
#endif

class Console
{
    private:

        unsigned int mWidth;
        unsigned int mHeight;
        float        mAspect;
        GLFWwindow*  mWindow;
        bool         mCloseRequested;
        

    public:

        Console(unsigned int aWidth, unsigned int aHeight, const char* aTitle);

        GLFWwindow* GetWindow() { return mWindow; }

};

