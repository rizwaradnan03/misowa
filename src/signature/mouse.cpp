#include <signature/mouse.h>

std::pair<double, double> Mouse::get_position(){
    return input::mouse_position();
}

void Mouse::Execute(){
    std::string* inp = input::mouse_pressed();
    if(inp == nullptr){
        return;
    }
    
    std::pair<double, double> mPos = input::mouse_position();

    Area_Hit* ah = new Area_Hit(nullptr, (double)mPos.first, (double)mPos.second, 30.0f, 30.0f);
    G_SINGLETON_action->set_push_action_hit(ah);
}