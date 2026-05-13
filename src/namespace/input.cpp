#include <namespace/input.h>
#include <GLFW/glfw3.h>
#include <singleton/gl.h>

namespace input {
    std::string* continuous_pressed(){
        std::string* ret = nullptr;

        if(glfwGetKey(G_SINGLETON_gl->get(), GLFW_KEY_W) == GLFW_PRESS){
            ret = new std::string("TOP");
        }else if(glfwGetKey(G_SINGLETON_gl->get(), GLFW_KEY_S) == GLFW_PRESS){
            ret = new std::string("BOTTOM");
        }else if(glfwGetKey(G_SINGLETON_gl->get(), GLFW_KEY_A) == GLFW_PRESS){
            ret = new std::string("LEFT");
        }else if(glfwGetKey(G_SINGLETON_gl->get(), GLFW_KEY_D) == GLFW_PRESS){
            ret = new std::string("RIGHT");
        }

        return ret;
    }
}