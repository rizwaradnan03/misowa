#include <singleton/gl.h>

SINGLETON_GL* G_SINGLETON_gl = nullptr;

GLFWwindow* SINGLETON_GL::get(){
    return this->window;
}

void SINGLETON_GL::set(GLFWwindow* value){
    this->window = value;
}