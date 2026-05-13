#include <namespace/input.h>
#include <GLFW/glfw3.h>
#include <singleton/gl.h>

namespace input {
    std::string* continuous_pressed(){
        std::string* ret = nullptr;

        if(glfwGetKey(G_SINGLETON_gl->get(), GLFW_KEY_W) == GLFW_PRESS){
            ret = new std::string("W");
        }else if(glfwGetKey(G_SINGLETON_gl->get(), GLFW_KEY_S) == GLFW_PRESS){
            ret = new std::string("S");
        }

        return ret;
    }
}