#include <source/particle/p_gun.h>

PARTICLE_gun::PARTICLE_gun(Transform* transform, Mesh* mesh, Material* material, BulletType bulletType, PoleSet poleSet): PARTICLE_item(transform, mesh, material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_bullet_type(bulletType);
    this->set_pole_set(poleSet);
    this->set_elapse_shoot(nullptr);
}

PARTICLE_gun::~PARTICLE_gun(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();
}

Transform* PARTICLE_gun::get_transform(){
    return this->transform;
}

void PARTICLE_gun::set_transform(Transform* value){
    this->transform = value;
}

Mesh* PARTICLE_gun::get_mesh(){
    return this->mesh;
}

void PARTICLE_gun::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* PARTICLE_gun::get_material(){
    return this->material;
}

void PARTICLE_gun::set_material(Material* value){
    this->material = value;
}

BulletType PARTICLE_gun::get_bullet_type(){
    return this->bullet_type;
}

void PARTICLE_gun::set_bullet_type(BulletType value){
    this->bullet_type = value;
}

PoleSet PARTICLE_gun::get_pole_set(){
    return this->pole_set;
}

void PARTICLE_gun::set_pole_set(PoleSet value){
    this->pole_set = value;
}

std::chrono::time_point<std::chrono::high_resolution_clock>* PARTICLE_gun::get_elapse_shoot(){
    return this->elapse_shoot;
}

void PARTICLE_gun::set_elapse_shoot(std::chrono::time_point<std::chrono::high_resolution_clock>* value){
    this->elapse_shoot = value;
}

void PARTICLE_gun::action(){
    std::string* mPress = input::mouse_pressed();
    if(mPress == nullptr || *mPress == "RIGHT"){
        return;
    }
 
    std::chrono::time_point<std::chrono::high_resolution_clock>* elap = this->get_elapse_shoot();
    if(elap != nullptr){
        return;
    }

    std::pair<float, float> pos = input::mouse_position();
    pos.first = pos.first + -420.0f;
    pos.second = pos.second + -300.0f;

    pos.first = G_OBJECT_player->get_transform()->get_x() + pos.first;
    pos.second = G_OBJECT_player->get_transform()->get_y() + pos.second;

    Target tg;
    tg.x = pos.first;
    tg.y = pos.second;

    BulletInterval bInterv;

    if(pos.first < 0){
        pos.first *= -1;
    }

    if(pos.second < 0.f){
        pos.second *= -1;
    }

    float hg = pos.first;
    if(pos.second > pos.first){
        hg = pos.second;
    }

    bInterv.x = pos.first / hg;
    bInterv.y = pos.second / hg;

    Transform* bTrans = new Transform(this->get_transform()->get_x(), this->get_transform()->get_y(), 10, 10);

    float wH = bTrans->get_w() / 2;
    float hH = bTrans->get_h() / 2;

    float vert[] = {
        bTrans->get_x() - wH, bTrans->get_y() - hH,
        bTrans->get_x() + wH, bTrans->get_y() - hH,
        bTrans->get_x() + wH, bTrans->get_y() + hH,
        bTrans->get_x() - wH, bTrans->get_y() + hH,
    };
    Mesh* bMesh = new Mesh(vert, 8);

    std::vector<float> col = color::find_rgba_color_by_name(color::GREEN);
    Material* bMat = new Material(col[0], col[1], col[2], col[3]);

    Entity* pcl = new PARTICLE_bullet(bTrans, bMesh, bMat, tg, 20, BulletType::PISTOL, bInterv);
    RTW->set_push_particle(pcl);

    std::chrono::time_point<std::chrono::high_resolution_clock>* current_time = new std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::high_resolution_clock::now());
    this->set_elapse_shoot(current_time);
}

void PARTICLE_gun::reset_elapse_shoot_checker(){
    std::chrono::time_point<std::chrono::high_resolution_clock>* elap = this->get_elapse_shoot();
    if(elap == nullptr){
        return;
    }

    auto current_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> differ = current_time - *elap;
    if(differ.count() >= 0.7f){
        this->set_elapse_shoot(nullptr);
    }
}

void PARTICLE_gun::Execute(){
    this->reset_elapse_shoot_checker();
    this->action();
    this->Display();
}

void PARTICLE_gun::Display(){
    Transform* pTrans = G_OBJECT_player->get_transform();
    PoleSet pSet = this->get_pole_set();

    this->get_transform()->set_x(pTrans->get_x() + pSet.x);
    this->get_transform()->set_y(pTrans->get_y() + pSet.y);

    this->get_material()->Execute(this->get_transform());
    this->get_mesh()->Execute(this->get_transform());
}