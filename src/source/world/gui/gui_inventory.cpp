#include <source/world/gui/gui_inventory.h>

GUI_inventory::GUI_inventory(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet): GUI_container(transform, mesh, material, poleSet){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_pole_x(poleSet.x);
    this->set_pole_y(poleSet.y);
}

Transform* GUI_inventory::get_transform(){
    return this->transform;
}

void GUI_inventory::set_transform(Transform* value){
    this->transform = value;
}

Mesh* GUI_inventory::get_mesh(){
    return this->mesh;
}

void GUI_inventory::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* GUI_inventory::get_material(){
    return this->material;
}

void GUI_inventory::set_material(Material* value){
    this->material = value;
}

float GUI_inventory::get_pole_x(){
    return this->pole_x;
}

void GUI_inventory::set_pole_x(float value){
    this->pole_x = value;
}

float GUI_inventory::get_pole_y(){
    return this->pole_y;
}

void GUI_inventory::set_pole_y(float value){
    this->pole_y = value;
}

std::vector<Gui*> GUI_inventory::get_nodes(){
    return this->nodes;
}

void GUI_inventory::set_nodes(std::vector<Gui*> value){
    this->nodes = value;
}

void GUI_inventory::Execute(Transform* transform){
    Transform* changeTrans = new Transform(transform->get_x() + this->get_pole_x(), transform->get_y() + this->get_pole_y(), this->get_transform()->get_w(), this->get_transform()->get_h());
    this->set_transform(changeTrans);
    
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());

    for(int i = 0;i < this->get_nodes().size();i++){
        this->get_nodes()[i]->Execute(this->get_transform());
    }
}