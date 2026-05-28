#include <source/world/gui/gui_item.h>

GUI_item::GUI_item(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet, std::string* item) : Gui(transform, mesh, material, poleSet){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_pole_x(poleSet.x);
    this->set_pole_y(poleSet.y);
    this->set_item(item);
}

Transform* GUI_item::get_transform(){
    return this->transform;
}

void GUI_item::set_transform(Transform* value){
    this->transform = value;
}

Mesh* GUI_item::get_mesh(){
    return this->mesh;
}

void GUI_item::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* GUI_item::get_material(){
    return this->material;
}

void GUI_item::set_material(Material* value){
    this->material = value;
}

float GUI_item::get_pole_x(){
    return this->pole_x;
}

void GUI_item::set_pole_x(float value){
    this->pole_x = value;
}

float GUI_item::get_pole_y(){
    return this->pole_y;
}

void GUI_item::set_pole_y(float value){
    this->pole_y = value;
}

std::string* GUI_item::get_item(){
    return this->item;
}

void GUI_item::set_item(std::string* value){
    this->item = value;
}

void GUI_item::hit_action(){
    std::pair<float, float> mPos = input::mouse_position();

    float wH = this->get_transform()->get_w() / 2;
    float hH = this->get_transform()->get_h() / 2;

    float left = this->get_transform()->get_x() - wH;
    float right = this->get_transform()->get_x() + wH;
    float top = this->get_transform()->get_y() + hH;
    float bottom = this->get_transform()->get_y() + hH;

    if(mPos.first >= left && mPos.first <= right && mPos.second <= top && mPos.second >= bottom){
        std::string* mAct = input::mouse_pressed();
        if(mAct == nullptr){
            return;
        }

        G_SINGLETON_player->set_select_item(this->get_item());
    }
}

void GUI_item::Execute(Transform* transform){
    Transform* changeTrans = new Transform(transform->get_x() + this->get_pole_x(), transform->get_y() + this->get_pole_y(), this->get_transform()->get_w(), this->get_transform()->get_h());
    this->set_transform(changeTrans);

    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());
    this->hit_action();
}