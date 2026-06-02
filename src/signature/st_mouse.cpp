#include <signature/st_mouse.h>

Mouse::Mouse(){}

std::pair<float, float> Mouse::get_position(){
    return input::mouse_position();
}

void Mouse::Execute(){
    std::string* inp = input::mouse_pressed();
    if(inp == nullptr){
        return;
    }
    
    std::pair<float, float> mPos = input::mouse_position();

    Area_Hit* ah = new Area_Hit(nullptr, (float)mPos.first, (float)mPos.second, 30.0f, 30.0f);
    G_SINGLETON_action->set_push_action_object_hit(ah);
}