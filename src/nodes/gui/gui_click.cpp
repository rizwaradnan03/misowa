#include <nodes/gui/gui_click.h>

GUI_click::GUI_click(Transform* transform, Mesh* mesh, Material* material) : Gui(transform, mesh, material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
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

void GUI_click::click(){

}

void GUI_click::Execute(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform()->get_x(), this->get_transform()->get_y());
    this->click();
}