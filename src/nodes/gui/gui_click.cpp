#include <nodes/gui/gui_click.h>

GUI_click::GUI_click(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet) : Gui(transform, mesh, material, poleSet){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_pole_x(poleSet.x);
    this->set_pole_y(poleSet.y);
}

Transform* GUI_click::get_transform(){
    return this->transform;
}

void GUI_click::set_transform(Transform* value){
    this->transform = value;
}

Mesh* GUI_click::get_mesh(){
    return this->mesh;
}

void GUI_click::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* GUI_click::get_material(){
    return this->material;
}

void GUI_click::set_material(Material* value){
    this->material = value;
}

float GUI_click::get_pole_x(){
    return this->pole_x;
}

void GUI_click::set_pole_x(float value){
    this->pole_x = value;
}

float GUI_click::get_pole_y(){
    return this->pole_y;
}

void GUI_click::set_pole_y(float value){
    this->pole_y = value;
}

void GUI_click::hit_action(){}

void GUI_click::Execute(Transform* transform){
    Transform* changeTrans = new Transform(transform->get_x() + this->get_pole_x(), transform->get_y() + this->get_pole_y(), this->get_transform()->get_w(), this->get_transform()->get_h());
    this->set_transform(changeTrans);

    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());
    this->hit_action();
}