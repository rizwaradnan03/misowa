#include <nodes/body/static.h>
#include <iostream>

BODY_Static::BODY_Static(int32_t x, int32_t y, int32_t w, int32_t h) : Body(x, y, w, h){
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

Transform* BODY_Static::get_transform(){
    return this->transform;
}

void BODY_Static::set_transform(Transform* value){
    this->transform = value;
}

Mesh* BODY_Static::get_mesh(){
    return this->mesh;
}

void BODY_Static::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* BODY_Static::get_material(){
    return this->material;
}

void BODY_Static::set_material(Material* value){
    this->material = value;
}

void BODY_Static::physic(const std::vector<Body*>& objects){
    this->object_collide(objects);
}

void BODY_Static::object_collide(const std::vector<Body*>& objects){}

void BODY_Static::trigger_change_position(){
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

void BODY_Static::Run(const std::vector<Body*>& objects){
    this->physic(objects);    
    this->Display();
}

void BODY_Static::Display(){
    this->get_mesh()->Execute();
    this->get_material()->Execute(this->get_transform()->get_x(), this->get_transform()->get_y());
}