#include <nodes/body/body.h>
#include <iostream>

Body::Body(Transform* transform, Mesh* mesh, Material* material): Entity(transform, mesh, material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
}

Transform* Body::get_transform(){
    return this->transform;
}

void Body::set_transform(Transform* value){
    this->transform = value;
}

Mesh* Body::get_mesh(){
    return this->mesh;
}

void Body::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* Body::get_material(){
    return this->material;
}

void Body::set_material(Material* value){
    this->material = value;
}

Attribute* Body::get_attribute(){
    return this->attribute;
}

void Body::set_attribute(Attribute* value){
    this->attribute = value;
}

Box_hit* Body::get_box_hit(){
    return this->box_hit;
}

void Body::set_box_hit(Box_hit* value){
    this->box_hit = value;
}

void Body::physic(const std::vector<Body*>& objects){
    this->object_collide(objects);
}

void Body::object_collide(const std::vector<Body*>& objects){}

void Body::Execute(const std::vector<Body*>& objects){
    this->physic(objects);    
    this->Display();
}

void Body::Display(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());
}