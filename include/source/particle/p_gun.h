#ifndef PARTICLE_GUN_H
#define PARTICLE_GUN_H

#include <iostream>
#include <chrono>
#include <dto/dto_bullet.h>
#include <dto/dto_poleset.h>
#include <nodes/2d/2d_entity.h>
#include <nodes/particle/p_item.h>
#include <source/particle/p_bullet.h>
#include <render_type/rt_world.h>
#include <source/scene/world/object/player.h>

class PARTICLE_gun: public PARTICLE_item {
    public:
        PARTICLE_gun(Transform* transform, Mesh* mesh, Material* material, BulletType bulletType, PoleSet poleSet);
        ~PARTICLE_gun();

        Transform* get_transform() override;
        void set_transform(Transform* value) override;

        Mesh* get_mesh() override;
        void set_mesh(Mesh* value) override;

        Material* get_material() override;
        void set_material(Material* value) override;

        BulletType get_bullet_type();
        void set_bullet_type(BulletType value);

        PoleSet get_pole_set();
        void set_pole_set(PoleSet value);

        std::chrono::time_point<std::chrono::high_resolution_clock>* get_elapse_shoot();
        void set_elapse_shoot(std::chrono::time_point<std::chrono::high_resolution_clock>* value);

        void action();
        void reset_elapse_shoot_checker();

        void Execute();
        void Display();
        
    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        Attribute* attribute;

        BulletType bullet_type;

        PoleSet pole_set;

        std::chrono::time_point<std::chrono::high_resolution_clock>* elapse_shoot;

        Box_hit* box_hit;
};

#endif