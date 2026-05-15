#include <graphics/transform.h>

Transform::Transform(int32_t x, int32_t y, int32_t w, int32_t h){
    this->set_x(x);
    this->set_y(y);
    this->set_w(w);
    this->set_h(h);
}

int32_t Transform::get_x(){
    return this->x;
}

void Transform::set_x(int32_t value){
    this->x = value;
}

int32_t Transform::get_y(){
    return this->y;
}

void Transform::set_y(int32_t value){
    this->y = value;
}

int32_t Transform::get_w(){
    return this->w;
}

void Transform::set_w(int32_t value){
    this->w = value;
}

int32_t Transform::get_h(){
    return this->h;
}

void Transform::set_h(int32_t value){
    this->h = value;
}