#include <source/particle/p_bullet.h>

PARTICLE_bullet::PARTICLE_bullet(Transform* transform, Mesh* mesh, Material* material, Target target): Entity(transform, mesh, material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_target(target);
}

PARTICLE_bullet::~PARTICLE_bullet(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();
    delete this->get_attribute();
    delete this->get_box_hit();
}

Transform* PARTICLE_bullet::get_transform(){
    return this->transform;
}

void PARTICLE_bullet::set_transform(Transform* value){
    this->transform = value;
}

Mesh* PARTICLE_bullet::get_mesh(){
    return this->mesh;
}

void PARTICLE_bullet::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* PARTICLE_bullet::get_material(){
    return this->material;
}

void PARTICLE_bullet::set_material(Material* value){
    this->material = value;
}

Attribute* PARTICLE_bullet::get_attribute(){
    return this->attribute;
}

void PARTICLE_bullet::set_attribute(Attribute* value){
    this->attribute = value;
}

Box_hit* PARTICLE_bullet::get_box_hit(){
    return this->box_hit;
}

void PARTICLE_bullet::set_box_hit(Box_hit* value){
    this->box_hit = value;
}

Target PARTICLE_bullet::get_target(){
    return this->target;
}

void PARTICLE_bullet::set_target(Target value){
    this->target = value;
}

void PARTICLE_bullet::Execute(const std::vector<Body*>& objects){
    this->Display();
    physic::move_y_and_x_defined_stuff(this, this->target.x, this->target.y);

    Transform* trans = this->get_transform();
    if(trans->get_x() == this->get_target().x && trans->get_y() == this->get_target().y){
        delete this;
    }
}

void PARTICLE_bullet::Display(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());
}