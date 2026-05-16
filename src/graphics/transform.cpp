#include <graphics/transform.h>

Transform::Transform(float x, float y, float w, float h){
    this->set_x(x);
    this->set_y(y);
    this->set_w(w);
    this->set_h(h);
}

float Transform::get_x(){
    return this->x;
}

void Transform::set_x(float value){
    this->x = value;
}

float Transform::get_y(){
    return this->y;
}

void Transform::set_y(float value){
    this->y = value;
}

float Transform::get_w(){
    return this->w;
}

void Transform::set_w(float value){
    this->w = value;
}

float Transform::get_h(){
    return this->h;
}

void Transform::set_h(float value){
    this->h = value;
}