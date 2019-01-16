#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#ifndef _BOX_timing_h_
#define _BOX_timing_h_
#endif

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
        
}