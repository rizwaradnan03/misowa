#include <nodes/gui/gui_container.h>

GUI_container::GUI_container(Transform* transform, Mesh* mesh, Material* material) : Gui(transform, mesh, material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
}

Transform* GUI_container::get_transform(){
    return this->transform;
}

void GUI_container::set_transform(Transform* value){
    this->transform = value;
}

Mesh* GUI_container::get_mesh(){
    return this->mesh;
}

void GUI_container::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* GUI_container::get_material(){
    return this->material;
}

void GUI_container::set_material(Material* value){
    this->material = value;
}

std::vector<Gui*> GUI_container::get_nodes(){
    return this->nodes;
}

void GUI_container::set_nodes(std::vector<Gui*> value){
    this->nodes = value;
}

void GUI_container::Execute(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());

    for(int i = 0;i < this->get_nodes().size();i++){
        this->get_nodes()[i]->Execute();
    }
}