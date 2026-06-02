#include <nodes/particle/p_item.h>

PARTICLE_item::PARTICLE_item(Transform* transform, Mesh* mesh, Material* material): Entity(transform, mesh, material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
}

PARTICLE_item::~PARTICLE_item(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();
}

Transform* PARTICLE_item::get_transform(){
    return this->transform;
}

void PARTICLE_item::set_transform(Transform* value){
    this->transform = value;
}

Mesh* PARTICLE_item::get_mesh(){
    return this->mesh;
}

void PARTICLE_item::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* PARTICLE_item::get_material(){
    return this->material;
}

void PARTICLE_item::set_material(Material* value){
    this->material = value;
}

void PARTICLE_item::Execute(){
    this->Display();
}

void PARTICLE_item::Display(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());
}