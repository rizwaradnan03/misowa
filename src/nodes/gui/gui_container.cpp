#include <nodes/gui/gui_container.h>

GUI_container::GUI_container(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet) : Gui(transform, mesh, material, poleSet){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_pole_x(poleSet.x);
    this->set_pole_y(poleSet.y);
}

GUI_container::~GUI_container(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();

    std::vector<Gui*> nd = this->get_nodes();

    for(int i = 0;i < nd.size();i++){
        delete nd[i];
    }
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

float GUI_container::get_pole_x(){
    return this->pole_x;
}

void GUI_container::set_pole_x(float value){
    this->pole_x = value;
}

float GUI_container::get_pole_y(){
    return this->pole_y;
}

void GUI_container::set_pole_y(float value){
    this->pole_y = value;
}

std::vector<Gui*> GUI_container::get_nodes(){
    return this->nodes;
}

void GUI_container::set_nodes(std::vector<Gui*> value){
    this->nodes = value;
}

void GUI_container::Execute(Transform* transform){
    Transform* changeTrans = new Transform(transform->get_x() + this->get_pole_x(), transform->get_y() + this->get_pole_y(), transform->get_w(), transform->get_h());
    this->set_transform(changeTrans);

    this->get_material()->Execute(this->get_transform());
    this->get_mesh()->Execute(this->get_transform());

    for(int i = 0;i < this->get_nodes().size();i++){
        this->get_nodes()[i]->Execute(this->get_transform());
    }
}