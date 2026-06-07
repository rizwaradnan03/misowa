#include <namespace/n_input.h>
#include <source/scene/world/object/player.h>

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

    std::pair<float, float> mouse_position_with_player_as_pole(){
        std::pair<float, float> mPos = mouse_position();

        float xVal = (mPos.first - sys::display::get_x_half()) + G_OBJECT_player->get_transform()->get_x();
        float yVal = (mPos.second - sys::display::get_y_half()) + G_OBJECT_player->get_transform()->get_y();
    
        return std::make_pair(xVal, yVal);
    }

    bool space_pressed(){
        if(glfwGetKey(G_SINGLETON_gl->get(), GLFW_KEY_SPACE) == GLFW_PRESS){
            return true;
        }

        return false;
    }
}