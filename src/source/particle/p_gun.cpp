#include <source/particle/p_gun.h>

PARTICLE_gun::PARTICLE_gun(Transform* transform, Mesh* mesh, Material* material, PARTICLE_bullet* bullet){
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