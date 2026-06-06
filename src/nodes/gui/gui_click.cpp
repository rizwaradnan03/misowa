#include <nodes/gui/gui_click.h>

GUI_click::GUI_click(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet) : Gui(transform, mesh, material, poleSet){
    this->set_id(identifier::generate_id("gui_click"));
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_pole_x(poleSet.x);
    this->set_pole_y(poleSet.y);
}

GUI_click::~GUI_click(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();
}

std::string GUI_click::get_id(){
    return this->id;
}

void GUI_click::set_id(std::string value){
    this->id = value;
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

void GUI_click::hit_action(){
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

    }
}

void GUI_click::Execute(Transform* transform){
    Transform* changeTrans = new Transform(transform->get_x() + this->get_pole_x(), transform->get_y() + this->get_pole_y(), this->get_transform()->get_w(), this->get_transform()->get_h());
    this->set_transform(changeTrans);

    this->get_material()->Execute(this->get_transform());
    this->get_mesh()->Execute(this->get_transform());
    this->hit_action();
}