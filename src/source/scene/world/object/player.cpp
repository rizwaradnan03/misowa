#include <source/scene/world/object/player.h>
#include <iostream>

Player* G_OBJECT_player = nullptr;

Player::Player(Transform* transform, Mesh* mesh, Material* material, Trait* trait) : BODY_Dynamic(transform, mesh, material, trait){
    Movement* iMovement = new Movement();
    
    Attribute* iAttr = new Attribute(5);
    Depth* iDepth = new Depth();

    Camera* iCam = new Camera(transform->get_x(), transform->get_y());
    Mouse* iMouse = new Mouse();

    Box_hit* box_hit = new Box_hit();

    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_trait(trait);
    this->set_camera(iCam);
    this->set_mouse(iMouse);
    this->set_movement(iMovement);
    this->set_attribute(iAttr);
    this->set_depth(iDepth);

    G_OBJECT_player = this;
}

Player::~Player(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();
    delete this->get_movement();
    delete this->get_camera();
    delete this->get_mouse();
    delete this->get_trait();
    delete this->get_attribute();
    delete this->get_depth();
    delete this->get_box_hit();

    std::vector<GUI_container*> gc = this->get_gui_containers();
    for(int i = 0;i < gc.size();i++){
        delete gc[i];
    }
}

Transform* Player::get_transform(){
    return this->transform;
}

void Player::set_transform(Transform* value){
    this->transform = value;
}

Mesh* Player::get_mesh(){
    return this->mesh;
}

void Player::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* Player::get_material(){
    return this->material;
}

void Player::set_material(Material* value){
    this->material = value;
}

Movement* Player::get_movement(){
    return this->movement;
}

void Player::set_movement(Movement* value){
    this->movement = value;
}

Camera* Player::get_camera(){
    return this->camera;
}

void Player::set_camera(Camera* value){
    this->camera = value;
}

Mouse* Player::get_mouse(){
    return this->mouse;
}

void Player::set_mouse(Mouse* value){
    this->mouse = value;
}

Attribute* Player::get_attribute(){
    return this->attribute;
}

void Player::set_attribute(Attribute* value){
    this->attribute = value;
}

Trait* Player::get_trait(){
    return this->trait;
}

void Player::set_trait(Trait* value){
    this->trait = value;
}

Depth* Player::get_depth(){
    return this->depth;
}

void Player::set_depth(Depth* value){
    this->depth = value;
}

Box_hit* Player::get_box_hit(){
    return this->box_hit;
}

void Player::set_box_hit(Box_hit* value){
    this->box_hit = value;
}

std::string* Player::get_select_item(){
    return this->select_item;
}

void Player::set_select_item(std::string* value){
    this->select_item = value;
}

PARTICLE_item* Player::get_holded_right(){
    return this->holded_right;
}

void Player::set_holded_right(PARTICLE_item* value){
    this->holded_right = value;
}

PARTICLE_item* Player::get_holded_left(){
    return this->holded_left;
}

void Player::set_holded_left(PARTICLE_item* value){
    this->holded_left = value;
}

std::vector<GUI_container*> Player::get_gui_containers(){
    return this->gui_containers;
}

void Player::set_gui_containers(std::vector<GUI_container*> value){
    this->gui_containers = value;
}

void Player::set_push_gui_containers(GUI_container* value){
    this->gui_containers.push_back(value);
}

void Player::physic(const std::vector<Body*>& objects){
    this->object_collide(objects);
}

void Player::object_collide(const std::vector<Body*>& objects){
    std::vector<float> vMe = this->mesh->get_verticles();
    bool point[] = {false, false, false, false};

    for(int i = 0;i < objects.size();i++){
        std::pair<bool, std::string*> cc = physic::check_collide(this->mesh, objects[i]->get_mesh());
        if(!cc.first){
            continue;
        }

        if(*cc.second == "TOP"){
            point[0] = true;
        }

        if(*cc.second == "BOTTOM"){
            point[1] = true;
        }

        if(*cc.second == "LEFT"){
            point[2] = true;
        }

        if(*cc.second == "RIGHT"){
            point[3] = true;
        }
    }

    if(point[1] == false){
        bool haveAnchor = this->get_trait()->find_exist(TraitType::ANCHOR);
        if(haveAnchor == false){
            if(this->get_movement()->get_elapse_jump() == nullptr){
                float prevVal = this->get_transform()->get_y();
                this->get_transform()->set_y(prevVal - dft::calc_displacement());
                this->get_movement()->trigger_change_position(this->get_transform(), this->get_mesh());
            }
        }
    }else{
        this->get_movement()->set_jump_stock(1);
        this->get_movement()->set_elapse_jump(nullptr);
    }

    this->get_movement()->move(this->get_transform(), this->get_mesh(), {point[0], point[1], point[2], point[3]});
}

void Player::camera_alligner(){
    this->get_camera()->update_position(this->get_transform()->get_x(), this->get_transform()->get_y());

    Shader* shd = this->get_material()->get_shader();

    int projLoc = glGetUniformLocation(shd->get_ID(), "projection");
    int viewLoc = glGetUniformLocation(shd->get_ID(), "view");
    int modelLoc = glGetUniformLocation(shd->get_ID(), "model");

    glUniformMatrix4fv(projLoc, 1, GL_FALSE, this->get_camera()->projection);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, this->get_camera()->view);

    float model[16] = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };
    
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model);
}

void Player::item_action(){
    if(this->get_holded_left() != nullptr){
        this->get_holded_left()->Execute();
    }
    
    if(this->get_holded_right() != nullptr){
        this->get_holded_left()->Execute();
    }
}

void Player::Run(const std::vector<Body*>& objects){
    this->camera_alligner();
    this->physic(objects);  
    this->hit_checker();  
    this->Display();

    this->get_mouse()->Execute();
    this->get_movement()->Execute(this->get_transform(), this->get_mesh());
    this->get_depth()->Execute(this->get_attribute());

    this->item_action();

    for(int i = 0;i < this->get_gui_containers().size();i++){
        GUI_container* gc = this->get_gui_containers()[i];
        gc->Execute(this->get_transform());
    }
}

void Player::hit_checker(){
    // std::string* inp = input::continuous_pressed();
    // if(inp != nullptr && *inp == "SPACE"){
    //     this->get_attribute()->hit(this->get_transform(), this->get_material()->get_shader());
    // }
}

void Player::Display(){
    this->get_attribute()->Execute(this->get_transform(), this->get_material()->get_shader());
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());
}