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

    Camera* cam = new Camera(x, y);

    this->set_transform(iTrans);
    this->set_mesh(iMesh);
    this->set_material(iMaterial);
    this->set_camera(cam);
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

Camera* Player::get_camera(){
    return this->camera;
}

void Player::set_camera(Camera* value){
    this->camera = value;
}

void Player::movement(){
    std::string* kb = input::continuous_pressed();
    if(kb == nullptr){
        return;
    }
 
    int32_t* tg = nullptr;
    bool p_or_m = false;

    if(*kb == "TOP"){
        tg = new int32_t(1);
    }else if(*kb == "RIGHT" || *kb == "LEFT"){
        tg = new int32_t(0);

        if(*kb == "RIGHT"){
            p_or_m = true;
        }else{
            p_or_m = false;
        }
    }

    if(tg == nullptr){
        return;
    }

    float prevVal;
    if(*tg == 1){
        prevVal = this->get_transform()->get_y();
        this->get_transform()->set_y(prevVal + (0.0005f * dft::PLAYER_speed));
    }else{
        prevVal = this->get_transform()->get_x();
        this->get_transform()->set_x(p_or_m ? prevVal + (0.0005f * dft::PLAYER_speed) : prevVal - (0.0005f * dft::PLAYER_speed));
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
    float xVal = this->get_transform()->get_x();
    float yVal = this->get_transform()->get_y();

    float wH = this->get_transform()->get_w() / 2;
    float hH = this->get_transform()->get_h() / 2;

    std::vector<float> crMesh = {
        xVal - wH, yVal - hH,
        xVal + wH, yVal - hH,
        xVal + wH, yVal + hH,
        xVal - wH, yVal + hH,
    };

    this->mesh->set_verticles(crMesh);
}

void Player::camera_alligner(){
    this->get_camera()->update_position(this->get_transform()->get_x(), this->get_transform()->get_y());

    Shader* shd = this->get_material()->get_shader();

    // take all the locations from gpu
    int projLoc = glGetUniformLocation(shd->get_ID(), "projection");
    int viewLoc = glGetUniformLocation(shd->get_ID(), "view");
    int modelLoc = glGetUniformLocation(shd->get_ID(), "model");

    // update everything
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, this->get_camera()->projection);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, this->get_camera()->view); // we try to look at our world

    float model[16] = { // use the default initialized position of verticle
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };
    
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model);
}

void Player::Run(const std::vector<Body*>& objects){
    this->physic(objects);    
    this->movement();
    this->camera_alligner();
    this->Display();
}

void Player::Display(){
    this->get_mesh()->Execute();
    this->get_material()->Execute(this->get_transform()->get_x(), this->get_transform()->get_y());
}