#include <source/scene/world/gui/gui_item.h>

GUI_item::GUI_item(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet, std::string* item, GuiItemType type, uint8_t amount): GUI_click(transform, mesh, material, poleSet){
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

std::chrono::time_point<std::chrono::high_resolution_clock>* GUI_item::get_elapse_choose(){
    return this->elapse_choose;
}

void GUI_item::set_elapse_choose(std::chrono::time_point<std::chrono::high_resolution_clock>* value){
    this->elapse_choose = value;
}

void GUI_item::hit_action(){
    std::pair<float, float> mPos = input::mouse_position();

    Transform* pTrans = G_OBJECT_player->get_transform();

    mPos.first = (mPos.first - 400) + pTrans->get_x();
    mPos.second = (mPos.second - 300) + pTrans->get_y();

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

        G_OBJECT_player->set_select_item(this->get_item());
    
        std::chrono::time_point<std::chrono::high_resolution_clock>* elaps = this->get_elapse_choose();
        if(elaps == nullptr){
            std::chrono::time_point<std::chrono::high_resolution_clock>* current_time = new std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::high_resolution_clock::now());
            this->set_elapse_choose(current_time);
        }else{
            PARTICLE_item* partItem;

            // G_OBJECT_player->set_holded_right();
        }
    }
}

void GUI_item::reset_elapse_choose_checker(){
    std::chrono::time_point<std::chrono::high_resolution_clock>* elap = this->get_elapse_choose();

    auto current_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> differ = current_time - *elap;
    if(differ.count() >= 0.7f){
        this->set_elapse_choose(nullptr);
    }
}

void GUI_item::Execute(Transform* transform){
    Transform* changeTrans = new Transform(transform->get_x() + this->get_pole_x(), transform->get_y() + this->get_pole_y(), this->get_transform()->get_w(), this->get_transform()->get_h());
    this->set_transform(changeTrans);

    this->get_material()->Execute(this->get_transform());
    this->get_mesh()->Execute(this->get_transform());
    this->reset_elapse_choose_checker();
    this->hit_action();
}