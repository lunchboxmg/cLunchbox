#include <iostream>

#include <core/windowz.hpp>

namespace WindowZ
{
    namespace
    {
        // Window - Context
        GLFWwindow*   mContext;
        unsigned int  mWidth;
        unsigned int  mHeight;
        float         mAspect;
        bool          mCloseRequested;
        bool          mInitialized;

        // Key State storage
        state_set     mKeysPressed;
        state_set     mKeysHeld;
        state_set     mKeysReleased;
        unsigned int  mKeysModBitfield;

        // Mouse State storage
        unsigned char mButtonState[NUM_BUTTONS];
        unsigned int  mButtonModBitField;

        // Mouse Cursor, Movement storage    
        float         mScrollOffset_x;
        float         mScrollOffset_y;
        float         mPos_x;
        float         mPos_y;
        float         mPos_dx;
        float         mPos_dy;

        // Timing
        double        mCurrent;
        double        mPrevious;
        double        mDelta;
        double        mFps;
        unsigned int  mCount;

    }

    int Initialize(unsigned int aWidth, unsigned int aHeight, const char* aTitle)
    {
        mInitialized = false;
        mWidth = aWidth;
        mHeight = aHeight;
        mAspect = (float) aWidth / (float) aHeight;

        // Initialize and configure GLFW
        if (!glfwInit())
        {
            std::cout << "GLFW did not initialize properly!" << std::endl;
            return -999;
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif
    
        // Create the GFLW Window
        mContext = glfwCreateWindow(mWidth, mHeight, "LearnOpenGL", NULL, NULL);
        if (mContext == nullptr)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -10;
        }
        glfwMakeContextCurrent(mContext);
        glfwSetFramebufferSizeCallback(mContext, WindowResizeCallback);

        // load all OpenGL function pointers
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            glfwTerminate();
            return -20;
        }

        // Set GLFW callbacks
        glfwSetKeyCallback(mContext, KeyCallback);
        glfwSetMouseButtonCallback(mContext, MouseButtonCallback);
        glfwSetScrollCallback(mContext, ScrollCallback);

        mInitialized = true;
        return 1;

    }

    // Window functions

    void SwapBuffers() { glfwSwapBuffers(mContext); }

    void Close() { glfwSetWindowShouldClose(mContext, GL_TRUE); }

    void RequestClose() { mCloseRequested = true; }

    // Window getters

    bool IsCloseRequested() { return mCloseRequested; }

    bool IsOpen()
    {
        return !glfwWindowShouldClose(mContext); // && !mCloseRequested;
    }

    float       GetWidth()   { return mWidth; }
    float       GetHeight()  { return mHeight; }
    float       GetAspect()  { return mAspect; }
    GLFWwindow* GetContext() { return mContext; }

    // Keyboard key state getters

    bool IsKeyPressed(int aKey)
    {
        return mKeysPressed.find(aKey) != mKeysPressed.end();
    }
    
    bool IsKeyHeld(int aKey)
    {
        return mKeysHeld.find(aKey) != mKeysHeld.end();
    }

    bool IsKeyReleased(int aKey)
    {
        return mKeysReleased.find(aKey) != mKeysReleased.end();
    }

    bool IsKeyModPressed(int aMod)
    {
        return mKeysModBitfield & aMod;
    }

    // Mouse button state getters

    bool IsButtonPressed(int aButton)
    {
        return mButtonState[aButton] & BUTTON_PRESSED;
    }

    bool IsButtonHeld(int aButton)
    {
        return mButtonState[aButton] & BUTTON_HELD;
    }

    bool IsButtonReleased(int aButton)
    {
        return mButtonState[aButton] & BUTTON_RELEASED;
    }

    bool IsModPressed(int aMod)
    {
        return mButtonModBitField & aMod;
    }

    // Mouse movement getters

    bool DidMouseMove()
    {
        return (mPos_dx != 0.0) || (mPos_dy != 0.0);
    }

    bool DidMouseScroll()
    {
        return (mScrollOffset_x != 0.0) || (mScrollOffset_y != 0.0);
    }

    float GetX()       { return mPos_x; }
    float GetY()       { return mPos_y; }
    float GetDX()      { return mPos_dx; }
    float GetDY()      { return mPos_dy; }
    float GetScrollX() { return mScrollOffset_x; }
    float GetScrollY() { return mScrollOffset_y; }

    // Timing, Clock getters

    double       GetDeviceTime()  { return glfwGetTime(); }
    double       GetCurrentTime() { return mCurrent; }
    double       GetDeltaTime()   { return mDelta; }
    double       GetFps()         { return mFps; }
    unsigned int GetCount()       { return mCount; }


    void Update()
    {
        // Clear Key State storage
        mKeysPressed.clear();
        mKeysReleased.clear();
        mKeysModBitfield = 0;

        // Clear ButtonState storage
        for (int i = 0; i < NUM_BUTTONS; i++)
        {
            if (mButtonState[i] > 0)
            {
                mButtonState[i] = mButtonState[i] ^ BUTTON_PRESSED ^ BUTTON_RELEASED;
            }
        }

        // Process events pending in the glfw event queue
        glfwPollEvents();

        // Get the current cursor position
        double cur_x = NO_CURSOR_VALUE;
        double cur_y = NO_CURSOR_VALUE;
        glfwGetCursorPos(mContext, &cur_x, &cur_y);
        if ((cur_x == NO_CURSOR_VALUE) || (cur_y == NO_CURSOR_VALUE))
        {
            std::cout << "ERROR: Could not get current cursor position." << std::endl;
        }

        // Set mouse movement data
        mPos_dx = cur_x - mPos_x;
        mPos_dy = cur_y - mPos_y;
        mPos_x = cur_x;
        mPos_y = cur_y;
        mScrollOffset_x = 0;
        mScrollOffset_y = 0;

        // Set internal timing, clock data
        double now = glfwGetTime();
        mDelta = now - mCurrent;
        mPrevious = mCurrent;
        mCurrent = now;
        mFps = 1.0 / mDelta;
        mCount++;

    }

    void Destroy()
    {
        glfwDestroyWindow(mContext);
        glfwTerminate();
    }

    // Callbacks section ... this is the reasoning behind the anonymous
    // namespace convention. The glfw callbacks are c functions and do not
    // understand the this pointer so you have to create a set method for
    // the class. Problem is, I do not want the state storage variables to be
    // altered by anything but the callbacks.

    void KeyCallback(GLFWwindow* aWindow, int aKey, int aScancode, int aAction, int aMods)
    {

        if (0 <= aKey && aKey <= 1024)
        {
            if (aAction == GLFW_PRESS)
            {
                if (mKeysPressed.find(aKey) == mKeysPressed.end())
                {
                    mKeysPressed.insert(aKey);
                    mKeysHeld.insert(aKey);
                }
            }
            if (aAction == GLFW_RELEASE)
            {
                mKeysHeld.erase(aKey);
                mKeysReleased.insert(aKey);
            }
            mKeysModBitfield = aMods;
            std::cout << "Frame: " << mCount << ", " << aKey << "\t" << aAction << "\t" << aMods << std::endl;
        }
    }

    void MouseButtonCallback(GLFWwindow* aWindow, int aButton, int aAction, int aMods)
    {
        if ((0 <= aButton) && (aButton < NUM_BUTTONS))
        {
            if (aAction == GLFW_PRESS)
            {
                if (mButtonState[aButton] && BUTTON_HELD)
                {
                    mButtonState[aButton] = BUTTON_PRESSED | BUTTON_HELD;
                }
            }
            if (aAction == GLFW_RELEASE)
            {
                mButtonState[aButton] ^= BUTTON_HELD;
                mButtonState[aButton] |= BUTTON_RELEASED;
            }
            mButtonModBitField = aMods;
        }
    }

    void ScrollCallback(GLFWwindow* aWindow, double aOffset_x, double aOffset_y)
    {
        mScrollOffset_x = aOffset_x;
        mScrollOffset_y = aOffset_y;
    }

    void WindowResizeCallback(GLFWwindow* aWindow, int aWidth, int aHeight)
    {
        mWidth = aWidth;
        mHeight = aHeight;
        glViewport(0, 0, aWidth, aHeight);
    }


}