#include <source/particle/p_gun.h>

PARTICLE_gun::PARTICLE_gun(Transform* transform, Mesh* mesh, Material* material, PARTICLE_bullet* bullet): PARTICLE_item(transform, mesh, material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_bullet(bullet);
}

PARTICLE_gun::~PARTICLE_gun(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();
    delete this->get_bullet();
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

PARTICLE_bullet* PARTICLE_gun::get_bullet(){
    return this->bullet;
}

void PARTICLE_gun::set_bullet(PARTICLE_bullet* value){
    this->bullet = value;
}

void PARTICLE_gun::action(){
    Target tg;
    tg.x = this->get_transform()->get_x();
    tg.y = this->get_transform()->get_y();

    Entity* pcl = new PARTICLE_bullet(this->get_transform(), this->get_mesh(), this->get_material(), tg, 20, BulletType::PISTOL);
    RTW->set_push_particle(pcl);
}

void PARTICLE_gun::Execute(){
    this->action();
    this->Display();
}

void PARTICLE_gun::Display(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());
}