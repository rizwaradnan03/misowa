#ifndef PARTICLE_BULLET_H
#define PARTICLE_BULLET_H

#include <vector>
#include <nodes/2d/2d_entity.h>
#include <glad/glad.h>
#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>
#include <signature/box/box_hit.h>
#include <signature/st_attribute.h>
#include <namespace/n_physic.h>
#include <dto/dto_bullet.h>
#include <iostream>

class PARTICLE_bullet: public Entity {
    public:
        PARTICLE_bullet(Transform* transform, Mesh* mesh, Material* material, Target target, uint8_t damage, BulletType type, BulletInterval interval);
        ~PARTICLE_bullet();

        Transform* get_transform();
        void set_transform(Transform* value);

        Mesh* get_mesh();
        void set_mesh(Mesh* value);

        Material* get_material();
        void set_material(Material* value);

        BulletType get_type();
        void set_type(BulletType value);

        BulletInterval get_interval();
        void set_interval(BulletInterval value);
        
        uint8_t get_damage();
        void set_damage(uint8_t value);
        
        Target get_target();
        void set_target(Target value);

        void projection();
        void Execute(const std::vector<Body*>& objects);
        void Display();
        
    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        BulletType type;
        BulletInterval interval;

        uint8_t damage;

        Target target;
};

#endif