#include <source/world/player.h>
#include <iostream>

Player::Player(int32_t x, int32_t y, int32_t w, int32_t h) : BODY_Dynamic(x, y, w, h){
    Transform* iTrans = new Transform(x, y, w, h);
    
    int32_t wH = w / 2;
    int32_t hH = h / 2;

    float vert[] = {
        (float)x - wH, (float)y - hH,
        (float)x + wH, (float)y - hH,
        (float)x + wH, (float)y + hH,
        (float)x - wH, (float)y + hH,
    };

    Mesh* iMesh = new Mesh(vert, 8);

    std::vector<float> col = color::find_rgba_color_by_name(color::BLUE);
    Material* iMaterial = new Material(col[0], col[1], col[2], col[3]);

    this->set_transform(iTrans);
    this->set_mesh(iMesh);
    this->set_material(iMaterial);
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

void Player::movement(){
    std::string* kb = input::continuous_pressed();
    if(kb == nullptr){
        return;
    }

    int32_t tg = 0;
    bool p_or_m = false;

    if(*kb == "TOP" || *kb == "BOTTOM"){
        tg = 1;
    }else{
        tg = 0;

        if(*kb == "RIGHT"){
            p_or_m = true;
        }else{
            p_or_m = false;
        }
    }

    int32_t prevVal;
    if(tg == 1){
        prevVal = this->transform->get_y();
        this->transform->set_y(prevVal - 0.1f);
    }else{
        prevVal = this->transform->get_x();
        this->transform->set_x(p_or_m ? prevVal + 0.1f : prevVal - 0.1f);
    }

    this->trigger_change_position();
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

        std::vector<float> vTarget = objects[i]->get_mesh()->get_verticles();
        int dFect;

        if(*cc.second == "TOP" || *cc.second == "BOTTOM"){
            dFect = 1;
        }else{
            dFect = 0;
        }

        if(point[1] == true){
            // gotta implement soon
        }

    }
}

void Player::trigger_change_position(){
    int32_t xVal = this->transform->get_x();
    int32_t yVal = this->transform->get_y();

    int32_t wH = this->transform->get_w() / 2;
    int32_t hH = this->transform->get_h() / 2;

    std::vector<float> crMesh = {
        (float)xVal - wH, (float)yVal - hH,
        (float)xVal + wH, (float)yVal - hH,
        (float)xVal + wH, (float)yVal + hH,
        (float)xVal - wH, (float)yVal + hH,
    };

    this->mesh->set_verticles(crMesh);
}

void Player::Run(const std::vector<Body*>& objects){
    this->physic(objects);    
    this->movement();
    this->Display();
}

void Player::Display(){
    // std::cout << "THE VERTICLE : " << this->get_mesh()->get_verticles()[0] << std::endl;
    this->get_mesh()->Execute();
    this->get_material()->Execute(this->get_transform()->get_x(), this->get_transform()->get_y());
}