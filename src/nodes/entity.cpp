#include <nodes/entity.h>

Entity::Entity(Transform* transform, Mesh* mesh, Material* material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
}

Transform* Entity::get_transform(){
    return this->transform;
}

void Entity::set_transform(Transform* value){
    this->transform = value;
}

Mesh* Entity::get_mesh(){
    return this->mesh;
}

void Entity::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* Entity::get_material(){
    return this->material;
}

void Entity::set_material(Material* value){
    this->material = value;
}

void Entity::Execute(const std::vector<Body*>& objects){
    this->Display();
}

void Entity::Display(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());
}