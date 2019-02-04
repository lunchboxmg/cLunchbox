#include <unordered_set>

#include <vendor/glad/glad.h>
#include <vendor/GLFW/glfw3.h>

#ifndef BOX_WINDOWZ
#define BOX_WINDOWZ

#define KEY_PRESSED     0x01
#define KEY_HELD        0x02
#define KEY_RELEASED    0x04

#define BUTTON_PRESSED  0x01
#define BUTTON_HELD     0x02
#define BUTTON_RELEASED 0x04
#define NUM_BUTTONS     GLFW_MOUSE_BUTTON_LAST + 1

#define NO_CURSOR_VALUE -9e9

typedef std::unordered_set<int> state_set;

namespace WindowZ
{
    int Initialize(unsigned int aWidth, unsigned int aHeight, const char* aTitle);

    // Window functions
    void SwapBuffers();
    void Close();
    void RequestClose();
    bool IsCloseRequested();
    bool IsOpen();
    float GetWidth();
    float GetHeight();
    float GetAspect();
    GLFWwindow* GetContext();

    // Keyboard interaction functions
    bool IsKeyPressed(int aKey);
    bool IsKeyHeld(int aKey);
    bool IsKeyReleased(int aKey);
    bool IsKeyModPressed(int aMod);

    // Mouse interaction functions
    bool IsButtonPressed(int aButton);
    bool IsButtonHeld(int aButton);
    bool IsButtonReleased(int aButton);
    bool IsModPressed(int aMod);
    bool DidMouseMove();
    bool DidMouseSroll();
    float GetX();
    float GetY();
    float GetDX();
    float GetDY();
    float GetScrollX();
    float GetScrollY();

    // Clock getters
    double GetDeviceTime();
    double GetCurrentTime();
    double GetDeltaTime();
    double GetFps();
    unsigned int GetCount();

    void Update();
    void Destroy();

    // Callbacks
    void KeyCallback(GLFWwindow* aWindow, int aKey, int aScancode, int aAction, int aMods);
    void MouseButtonCallback(GLFWwindow* aWindow, int aButton, int aAction, int aMods);
    void ScrollCallback(GLFWwindow* aWindow, double aOffset_x, double aOffset_y);
    void WindowResizeCallback(GLFWwindow* aWindow, int aWidth, int aHeight);

}

#endif