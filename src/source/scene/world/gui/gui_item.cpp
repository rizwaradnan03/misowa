#include <source/scene/world/gui/gui_item.h>

GUI_item::GUI_item(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet, std::string* item, GuiItemType type, uint8_t amount): GUI_click(transform, mesh, material, poleSet){
    this->set_id(identifier::generate_id("gui_item"));
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_pole_x(poleSet.x);
    this->set_pole_y(poleSet.y);
    this->set_item(item);
    this->set_type(type);
    this->set_amount(amount);
}

GUI_item::~GUI_item(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();
    delete this->get_item();
}

std::string GUI_item::get_id(){
    return this->id;
}

void GUI_item::set_id(std::string value){
    this->id = value;
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

GuiItemType GUI_item::get_type(){
    return this->type;
}

void GUI_item::set_type(GuiItemType value){
    this->type = value;
}

uint8_t GUI_item::get_amount(){
    return this->amount;
}

void GUI_item::set_amount(uint8_t value){
    this->amount = value;
}

void GUI_item::Execute(Transform* transform){
    this->get_transform()->set_x(transform->get_x() + this->get_pole_x());
    this->get_transform()->set_y(transform->get_y() + this->get_pole_y());
    
    this->get_material()->Execute(this->get_transform());
    this->get_mesh()->Execute(this->get_transform());
}