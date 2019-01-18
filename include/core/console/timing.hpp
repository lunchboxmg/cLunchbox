#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#ifndef BOX_TIMING_HPP
#define BOX_TIMING_HPP

class BOX_Timing
{
    private:

        float mCurrent;
        float mPrevious;
        float mDelta;
        float mCount;
        float mFps;

    public:

        BOX_Timing();

        void Update();

        float GetDeviceTime();
        float GetCurrent();
        float GetDelta();
        float GetFps();
        float GetCount();
        
};

#endif
