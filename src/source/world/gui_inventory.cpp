#include <source/world/gui_inventory.h>

GUI_inventory::GUI_inventory(Transform* transform, Mesh* mesh, Material* material): GUI_container(transform, mesh, material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
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

std::vector<Gui*> GUI_inventory::get_nodes(){
    return this->nodes;
}

void GUI_inventory::set_nodes(std::vector<Gui*> value){
    this->nodes = value;
}

void GUI_inventory::Execute(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform()->get_x(), this->get_transform()->get_y());

    for(int i = 0;i < this->get_nodes().size();i++){
        this->get_nodes()[i]->Execute();
    }
}