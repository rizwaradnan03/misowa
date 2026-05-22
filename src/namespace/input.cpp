#include <namespace/input.h>

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
        }else if(glfwGetKey(G_SINGLETON_gl->get(), GLFW_KEY_SPACE) == GLFW_PRESS){
            ret = new std::string("SPACE");
        }

        return ret;
    }

    std::pair<double, double> mouse_position(){
        double xPos, yPos;
        glfwGetCursorPos(G_SINGLETON_gl->get(), &xPos, &yPos);

        return std::make_pair(xPos, yPos);
    }
}