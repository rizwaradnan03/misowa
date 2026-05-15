#include <nodes/body/body.h>
#include <iostream>

Body::Body(int32_t x, int32_t y, int32_t w, int32_t h){
    Transform* iTrans = new Transform(x, y, w, h);
    
    int32_t wH = w / 2;
    int32_t hH = h / 2;

    float vert[] = {
        (float)x - wH, (float)y - hH,
        (float)x + wH, (float)y - hH,
        (float)x + wH, (float)y + hH,
        (float)x - wH, (float)y + hH,
    };

    Mesh* iMesh = new Mesh(vert, 8);

    std::vector<float> col = color::find_rgba_color_by_name(color::BLUE);
    Material* iMaterial = new Material(col[0], col[1], col[2], col[3]);

    this->set_transform(iTrans);
    this->set_mesh(iMesh);
    this->set_material(iMaterial);
}

Transform* Body::get_transform(){
    return this->transform;
}

void Body::set_transform(Transform* value){
    this->transform = value;
}

Mesh* Body::get_mesh(){
    return this->mesh;
}

void Body::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* Body::get_material(){
    return this->material;
}

void Body::set_material(Material* value){
    this->material = value;
}

void Body::physic(const std::vector<Body*>& objects){
    this->object_collide(objects);
}

void Body::object_collide(const std::vector<Body*>& objects){}

void Body::trigger_change_position(){
    int32_t xVal = this->transform->get_x();
    int32_t yVal = this->transform->get_y();

    int32_t wH = this->transform->get_w() / 2;
    int32_t hH = this->transform->get_h() / 2;

    std::vector<float> crMesh = {
        (float)xVal - wH, (float)yVal - hH,
        (float)xVal + wH, (float)yVal - hH,
        (float)xVal + wH, (float)yVal + hH,
        (float)xVal - wH, (float)yVal + hH,
    };

    this->mesh->set_verticles(crMesh);
}

void Body::Run(const std::vector<Body*>& objects){
    this->physic(objects);    
    this->Display();
}

void Body::Display(){
    this->get_material()->Execute(this->get_transform()->get_x(), this->get_transform()->get_y());
    this->get_mesh()->Execute();
}