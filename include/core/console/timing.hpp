#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#ifndef BOX_TIMING_HPP
#define BOX_TIMING_HPP

class BOX_Timing
{
    private:

        double       mCurrent;
        double       mPrevious;
        double       mDelta;
        double       mFps;
        unsigned int mCount;

    public:

        BOX_Timing();

        void Update();

        double       GetDeviceTime() { return glfwGetTime(); }
        double       GetCurrent()    { return mCurrent; }
        double       GetDelta()      { return mDelta; }
        double       GetFps()        { return mFps; }
        unsigned int GetCount()      { return mCount; }
        
};

#endif
