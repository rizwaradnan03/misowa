#include <nodes/body/dynamic.h>
#include <iostream>

BODY_Dynamic::BODY_Dynamic(float x, float y, float w, float h) : Body(x, y, w, h){
    Transform* iTrans = new Transform(x, y, w, h);
    
    float wH = w / 2;
    float hH = h / 2;

    float vert[] = {
        x - wH, y - hH,
        x + wH, y - hH,
        x + wH, y + hH,
        x - wH, y + hH,
    };

    Mesh* iMesh = new Mesh(vert, 8);

    std::vector<float> col = color::find_rgba_color_by_name(color::BLUE);
    Material* iMaterial = new Material(col[0], col[1], col[2], col[3]);

    Camera* iCam = new Camera(x, y);
    Movement* iMovement = new Movement();

    this->set_transform(iTrans);
    this->set_mesh(iMesh);
    this->set_material(iMaterial);
    this->set_camera(iCam);
    this->set_movement(iMovement);
}

Transform* BODY_Dynamic::get_transform(){
    return this->transform;
}

void BODY_Dynamic::set_transform(Transform* value){
    this->transform = value;
}

Mesh* BODY_Dynamic::get_mesh(){
    return this->mesh;
}

void BODY_Dynamic::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* BODY_Dynamic::get_material(){
    return this->material;
}

void BODY_Dynamic::set_material(Material* value){
    this->material = value;
}

Movement* BODY_Dynamic::get_movement(){
    return this->movement;
}

void BODY_Dynamic::set_movement(Movement* value){
    this->movement = value;
}

Camera* BODY_Dynamic::get_camera(){
    return this->camera;
}

void BODY_Dynamic::set_camera(Camera* value){
    this->camera = value;
}

void BODY_Dynamic::physic(const std::vector<Body*>& objects){
    this->object_collide(objects);
}

void BODY_Dynamic::object_collide(const std::vector<Body*>& objects){}

void BODY_Dynamic::trigger_change_position(){}

void BODY_Dynamic::camera_alligner(){}

void BODY_Dynamic::Run(const std::vector<Body*>& objects){
    this->camera_alligner();
    this->physic(objects);    
    this->Display();
}

void BODY_Dynamic::Display(){
    this->get_mesh()->Execute();
    this->get_material()->Execute(this->get_transform()->get_x(), this->get_transform()->get_y());
    this->get_movement()->Execute(this->get_transform(), this->get_mesh());
}