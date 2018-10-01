#include "Display.h"

Display::Display()
{
    LOG_DEBUG("Open new Display " << this);

    setupWindow();
    setupGL();
}

Display::~Display()
{
    LOG_DEBUG("Close Display " << this);

    glfwDestroyWindow(_window);
    glfwTerminate();
}

void Display::begin()
{
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::enable3D()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void Display::disable3D()
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
}

void Display::end()
{
    glfwSwapBuffers(_window);
}

void Display::setupWindow()
{
    Config* config = Config::get();

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_SAMPLES, 4);

    _window = glfwCreateWindow(config->width, config->height, config->title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(_window);
}

void Display::setupGL()
{
    glewExperimental = GL_TRUE;
    glewInit();

    glClearColor(0.3f, 0.5f, 0.4f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

GLFWwindow *Display::window() const
{
    return _window;
}

void Display::setWindow(GLFWwindow *window)
{
    _window = window;
}
