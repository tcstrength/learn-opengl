#ifndef DISPLAY_H
#define DISPLAY_H

#include "../Utils/Config.h"

class Display {
public:
    Display();

    ~Display();

    void begin();

    void end();

    void enable3D();

    void disable3D();

    bool isOpen() { return !glfwWindowShouldClose(_window); }

    GLFWwindow *window() const;

    void setWindow(GLFWwindow *window);

private:

    void setupWindow();

    void setupGL();

    GLFWwindow* _window;

};

#endif // DISPLAY_H
