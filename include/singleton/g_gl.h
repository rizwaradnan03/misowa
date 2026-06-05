#ifndef SINGLETON_GL_H
#define SINGLETON_GL_H

#include <config/c_pch.h>

class SINGLETON_GL {
    public:
        void set(GLFWwindow* value);
        GLFWwindow* get();

    private:
        GLFWwindow* window;
};

extern SINGLETON_GL* G_SINGLETON_gl;

#endif