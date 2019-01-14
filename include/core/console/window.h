#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#ifndef _BOX_window_h_
#define _BOX_window_h_
#endif

class BOX_Window
{
    private:

        unsigned int mWidth;
        unsigned int mHeight;
        float        mAspect;
        GLFWwindow*  mWindow;
        bool         mCloseRequested;

    public:

        BOX_Window(unsigned int, unsigned int, const char*);

        int  CreateContext();
        void Swap();
        void Close();
        void RequestClose();
        bool IsCloseRequested();
        bool IsOpen();
        void Destroy();

        void SetDimensions(unsigned int, unsigned int);

        float        GetAspect()  { return mAspect; }
        GLFWwindow*  GetContext() { return mWindow; }
        unsigned int GetWidth()   { return mWidth; }
        unsigned int GetHeight()  { return mHeight; }

};
