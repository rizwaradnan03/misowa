#include <source/world/player.h>
#include <iostream>

Player::Player(float x, float y, float w, float h) : BODY_Dynamic(x, y, w, h){
    Transform* iTrans = new Transform(x, y, w, h);
    
    float wH = w / 2;
    float hH = h / 2;

    float vert[] = {
        x - wH, y - hH,
        x + wH, y - hH,
        x + wH, y + hH,
        x - wH, y + hH,
    };

    Mesh* iMesh = new Mesh(vert, 8);

    std::vector<float> col = color::find_rgba_color_by_name(color::BLUE);
    Material* iMaterial = new Material(col[0], col[1], col[2], col[3]);

    Camera* iCam = new Camera(x, y);
    Movement* iMovement = new Movement();

    Attribute* iAttr = new Attribute(5);
    Depth* iDepth = new Depth();

    Box_hit* box_hit = new Box_hit();

    this->set_transform(iTrans);
    this->set_mesh(iMesh);
    this->set_material(iMaterial);
    this->set_camera(iCam);
    this->set_movement(iMovement);
    this->set_attribute(iAttr);
    this->set_depth(iDepth);
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

Attribute* Player::get_attribute(){
    return this->attribute;
}

void Player::set_attribute(Attribute* value){
    this->attribute = value;
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
        // if(this->get_movement()->get_elapse_jump() == nullptr){
        //     float prevVal = this->get_transform()->get_y();
        //     this->get_transform()->set_y(prevVal - dft::calc_displacement());
        //     this->get_movement()->trigger_change_position(this->get_transform(), this->get_mesh()); // triggering to update the current position
        // }
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

void Player::Run(const std::vector<Body*>& objects){
    this->camera_alligner();
    this->physic(objects);  
    this->hit_checker();  
    this->Display();
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
    this->get_material()->Execute(this->get_transform()->get_x(), this->get_transform()->get_y());
    this->get_movement()->Execute(this->get_transform(), this->get_mesh());
    this->get_depth()->Execute(this->get_attribute());
}