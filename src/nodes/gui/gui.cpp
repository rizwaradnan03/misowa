#include <nodes/gui/gui.h>

Gui::Gui(Transform* transform, Mesh* mesh, Material* material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
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

void Gui::Execute(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform()->get_x(), this->get_transform()->get_y());
}