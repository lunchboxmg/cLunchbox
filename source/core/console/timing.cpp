#include <core/console/timing.hpp>

BOX_Timing::BOX_Timing():
    mCurrent(glfwGetTime()),
    mPrevious(mCurrent),
    mDelta(0),
    mCount(0),
    mFps(0)
{

}

void BOX_Timing::Update()
{
    double now = glfwGetTime();
    mDelta = now - mCurrent;
    mPrevious = mCurrent;
    mCurrent = now;
    mFps = 1.0 / mDelta;
    mCount++;
}