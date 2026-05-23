#include <signature/area/area_hit.h>

Area_Hit::Area_Hit(int32_t* damage, float x, float y, float w, float h){
    this->set_damage(damage);
    this->set_x(x);
    this->set_y(y);
    this->set_w(w);
    this->set_h(h);

    G_SINGLETON_action->set_push_action_hit(this);
}

int32_t* Area_Hit::get_damage(){
    return this->damage;
}

void Area_Hit::set_damage(int32_t* value){
    this->damage = value;
}

float Area_Hit::get_x(){
    return this->x;
}

void Area_Hit::set_x(float value){
    this->x = value;
}

float Area_Hit::get_y(){
    return this->y;
}

void Area_Hit::set_y(float value){
    this->y = value;
}

float Area_Hit::get_w(){
    return this->w;
}

void Area_Hit::set_w(float value){
    this->w = value;
}

float Area_Hit::get_h(){
    return this->h;
}

void Area_Hit::set_h(float value){
    this->h = value;
}