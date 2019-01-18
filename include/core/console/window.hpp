#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#ifndef BOX_WINDOW_HPP
#define BOX_WINDOW_HPP

class BOX_Window
{
    private:

        unsigned int mWidth;
        unsigned int mHeight;
        float        mAspect;
        GLFWwindow*  mWindow;
        bool         mCloseRequested;

    public:

        BOX_Window();
        BOX_Window(unsigned int, unsigned int, const char*);

        int  CreateContext();
        int  CreateContext(unsigned int, unsigned int, const char*);
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

#endif
