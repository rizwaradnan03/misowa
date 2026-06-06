#include <nodes/gui/gui.h>

Gui::Gui(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet): Entity(transform, mesh, material){
    this->set_id(identifier::generate_id("gui"));
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_pole_x(poleSet.x);
    this->set_pole_y(poleSet.y);
}

std::string Gui::get_id(){
    return this->id;
}

void Gui::set_id(std::string value){
    this->id = value;
}

Transform* Gui::get_transform(){
    return this->transform;
}

void Gui::set_transform(Transform* value){
    this->transform = value;
}

Mesh* Gui::get_mesh(){
    return this->mesh;
}

void Gui::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* Gui::get_material(){
    return this->material;
}

void Gui::set_material(Material* value){
    this->material = value;
}

float Gui::get_pole_x(){
    return this->pole_x;
}

void Gui::set_pole_x(float value){
    this->pole_x = value;
}

float Gui::get_pole_y(){
    return this->pole_y;
}

void Gui::set_pole_y(float value){
    this->pole_y = value;
}

void Gui::Execute(Transform* transform){
    Transform* changeTrans = new Transform(transform->get_x() + this->get_pole_x(), transform->get_y() + this->get_pole_y(), this->get_transform()->get_w(), this->get_transform()->get_h());
    this->set_transform(changeTrans);

    this->get_material()->Execute(this->get_transform());
    this->get_mesh()->Execute(this->get_transform());
}