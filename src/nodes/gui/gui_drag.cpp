#include <nodes/gui/gui_drag.h>

GUI_drag::GUI_drag(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet) : Gui(transform, mesh, material, poleSet){
    this->set_id(identifier::generate_id("gui_drag"));
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_pole_x(poleSet.x);
    this->set_pole_y(poleSet.y);
}

std::string GUI_drag::get_id(){
    return this->id;
}

void GUI_drag::set_id(std::string value){
    this->id = value;
}

Transform* GUI_drag::get_transform(){
    return this->transform;
}

void GUI_drag::set_transform(Transform* value){
    this->transform = value;
}

Mesh* GUI_drag::get_mesh(){
    return this->mesh;
}

void GUI_drag::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* GUI_drag::get_material(){
    return this->material;
}

void GUI_drag::set_material(Material* value){
    this->material = value;
}

float GUI_drag::get_pole_x(){
    return this->pole_x;
}

void GUI_drag::set_pole_x(float value){
    this->pole_x = value;
}

float GUI_drag::get_pole_y(){
    return this->pole_y;
}

void GUI_drag::set_pole_y(float value){
    this->pole_y = value;
}

void GUI_drag::drag_action(){
    std::pair<float, float> mPos = input::mouse_position();

    float wH = this->get_transform()->get_w() / 2;
    float hH = this->get_transform()->get_h() / 2;

    float left = this->get_transform()->get_x() - wH;
    float right = this->get_transform()->get_x() + wH;
    float top = this->get_transform()->get_y() + hH;
    float bottom = this->get_transform()->get_y() + hH;

    if(mPos.first >= left && mPos.first <= right && mPos.second <= top && mPos.second >= bottom){
        // the action
    }
}

void GUI_drag::Execute(Transform* transform){
    Transform* changeTrans = new Transform(transform->get_x() + this->get_pole_x(), transform->get_y() + this->get_pole_y(), this->get_transform()->get_w(), this->get_transform()->get_h());
    this->set_transform(changeTrans);

    this->get_material()->Execute(this->get_transform());
    this->get_mesh()->Execute(this->get_transform());
    this->drag_action();
}