#include <namespace/n_input.h>

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

    std::string* mouse_pressed(){
        std::string* ret = nullptr;

        int state = glfwGetMouseButton(G_SINGLETON_gl->get(), GLFW_MOUSE_BUTTON_LEFT);
        if(state == GLFW_PRESS){
            ret = new std::string("LEFT");
        }

        return ret;
    }

    std::pair<float, float> mouse_position(){
        double xPos, yPos;
        glfwGetCursorPos(G_SINGLETON_gl->get(), &xPos, &yPos);

        return std::make_pair((float)xPos, (float)yPos);
    }
}