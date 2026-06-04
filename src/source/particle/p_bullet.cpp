#include <source/particle/p_bullet.h>

PARTICLE_bullet::PARTICLE_bullet(Transform* transform, Mesh* mesh, Material* material, Target target, uint8_t damage, BulletType type, BulletInterval interval): Entity(transform, mesh, material){
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_target(target);
    this->set_damage(damage);
    this->set_type(type);
    this->set_interval(interval);
}

PARTICLE_bullet::~PARTICLE_bullet(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();
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

BulletType PARTICLE_bullet::get_type(){
    return this->type;
}

void PARTICLE_bullet::set_type(BulletType value){
    this->type = value;
}

BulletInterval PARTICLE_bullet::get_interval(){
    return this->interval;
}

void PARTICLE_bullet::set_interval(BulletInterval value){
    this->interval = value;
}

uint8_t PARTICLE_bullet::get_damage(){
    return this->damage;
}

void PARTICLE_bullet::set_damage(uint8_t value){
    this->damage = value;
}

Target PARTICLE_bullet::get_target(){
    return this->target;
}

void PARTICLE_bullet::set_target(Target value){
    this->target = value;
}

void PARTICLE_bullet::projection(){
    Transform* trans = this->get_transform();
    Target tg = this->get_target();

    BulletInterval bInterv = this->get_interval();

    if(trans->get_x() != tg.x){
        if(trans->get_x() > tg.x){
            bInterv.x = bInterv.x * -1.0f;
        }

        float calc = trans->get_x() + bInterv.x;
        if(trans->get_x() < tg.x){
            if(calc < tg.x){
                this->get_transform()->set_x(calc);
            }else{
                this->get_transform()->set_x(tg.x);
            }
        }else{
            if(calc > tg.x){
                this->get_transform()->set_x(calc);
            }else{
                this->get_transform()->set_x(tg.x);
            }
        }
    }

    if(trans->get_y() != tg.y){
        if(trans->get_y() > tg.y){
            bInterv.y *= -1;
        }

        float calc = trans->get_y() + bInterv.y;
        if(trans->get_y() < tg.y){
            if(calc < tg.y){
                this->get_transform()->set_y(calc);
            }else{
                this->get_transform()->set_y(tg.y);
            }
        }else{
            if(calc > tg.y){
                this->get_transform()->set_y(calc);
            }else{
                this->get_transform()->set_y(tg.y);
            }
        }
    }
}

void PARTICLE_bullet::Execute(const std::vector<Body*>& objects){
    this->projection();
    if(this == nullptr){
        Transform* trans = this->get_transform();
        if(trans->get_x() == this->get_target().x && trans->get_y() == this->get_target().y){
            std::cout << "DELETE NOTIFICATION" << std::endl;
            delete this;
        }
    }

    this->Display();
}

void PARTICLE_bullet::Display(){
    this->get_mesh()->Execute(this->get_transform());
    this->get_material()->Execute(this->get_transform());
}