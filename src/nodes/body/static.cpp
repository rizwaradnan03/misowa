#include <nodes/body/static.h>
#include <iostream>

BODY_Static::BODY_Static(float x, float y, float w, float h) : Body(x, y, w, h){
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

    std::vector<float> col = color::find_rgba_color_by_name(color::GREEN);
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
    float xVal = this->transform->get_x();
    float yVal = this->transform->get_y();

    float wH = this->transform->get_w() / 2;
    float hH = this->transform->get_h() / 2;

    std::vector<float> crMesh = {
        xVal - wH, yVal - hH,
        xVal + wH, yVal - hH,
        xVal + wH, yVal + hH,
        xVal - wH, yVal + hH,
    };

    this->mesh->set_verticles(crMesh);
}

void BODY_Static::Run(const std::vector<Body*>& objects){
    this->physic(objects);    
    this->Display();
}

void BODY_Static::Display(){
    // std::cout << "MY POS : " << this->get_transform()->get_x() << " " << this->get_transform()->get_y() << std::endl;
    this->get_mesh()->Execute();
    this->get_material()->Execute(this->get_transform()->get_x(), this->get_transform()->get_y());
}