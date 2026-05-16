#include <nodes/camera.h>

Camera::Camera(float x, float y){
    this->set_x(x);
    this->set_y(y);

    float left = -500.0f;
    float right = 500.0f;
    float bottom = -500.0f;
    float top = 500.0f;
    float nearZ = -1.0f;
    float farZ = 1.0f;

    this->projection[0] = 2.0f / (right - left);
    this->projection[1] = 0;
    this->projection[2] = 0;
    this->projection[3] = 0;

    this->projection[4] = 0;
    this->projection[5] = 2.0f / (top - bottom);
    this->projection[6] = 0;
    this->projection[7] = 0;

    this->projection[8] = 0;
    this->projection[9] = 0;
    this->projection[10] = -2.0f / (farZ - nearZ);
    this->projection[11] = 0;

    this->projection[12] = -(right + left) / (right - left);
    this->projection[13] = -(top + bottom) / (top - bottom);
    this->projection[14] = -(farZ + nearZ) / (farZ - nearZ);
    this->projection[15] = 1.0f;
}

float Camera::get_x(){
    return this->x;
}

void Camera::set_x(float value){
    this->x = value;
}

float Camera::get_y(){
    return this->y;
}

void Camera::set_y(float value){
    this->y = value;
}

void Camera::update_position(float x, float y){
    this->set_x(x);
    this->set_y(y);
    this->Execute();
}

void Camera::Execute(){
    this->view[0] = 1;
    this->view[1] = 0;
    this->view[2] = 0;
    this->view[3] = 0;
    this->view[4] = 0;
    this->view[5] = 1;
    this->view[6] = 0;
    this->view[7] = 0;
    this->view[8] = 0;
    this->view[9] = 0;
    this->view[10] = 1;
    this->view[11] = 0;
    this->view[12] = -this->get_x();
    this->view[13] = -this->get_y();
    this->view[14] = 0;
    this->view[15] = 1;
}