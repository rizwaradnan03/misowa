#include <singleton/g_action.h>

SINGLETON_action* G_SINGLETON_action = nullptr;

std::vector<Area_Hit*> SINGLETON_action::get_action_object_hit(){
    return this->action_object_hit;
}

void SINGLETON_action::set_action_object_hit(std::vector<Area_Hit*> value){
    this->action_object_hit = value;
}

void SINGLETON_action::set_push_action_object_hit(Area_Hit* value){
    this->action_object_hit.push_back(value);
}