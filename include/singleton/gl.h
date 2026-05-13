#pragma once

#include <GLFW/glfw3.h>

class SINGLETON_GL {
    public:
        void set(GLFWwindow* value);
        GLFWwindow* get();

    private:
        GLFWwindow* window;
};

extern SINGLETON_GL* G_SINGLETON_gl;