#include <nodes/body/body_static.h>
#include <iostream>

BODY_Static::BODY_Static(Transform* transform, Mesh* mesh, Material* material, Trait* trait) : Body(transform, mesh, material, trait){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_trait(trait);
}

Transform* BODY_Static::get_transform(){
    return this->transform;
}

void BODY_Static::set_transform(Transform* value){
    this->transform = value;
}

Mesh* BODY_Static::get_mesh(){
    return this->mesh;
}

void BODY_Static::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* BODY_Static::get_material(){
    return this->material;
}

void BODY_Static::set_material(Material* value){
    this->material = value;
}
Trait* BODY_Static::get_trait(){
    return this->trait;
}

void BODY_Static::set_trait(Trait* value){
    this->trait = value;
}

void BODY_Static::physic(const std::vector<Body*>& objects){
    this->object_collide(objects);
}

void BODY_Static::object_collide(const std::vector<Body*>& objects){}

void BODY_Static::Execute(const std::vector<Body*>& objects){
    this->physic(objects);    
    this->Display();
}

void BODY_Static::Display(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());
}