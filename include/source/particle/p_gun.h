#ifndef PARTICLE_GUN_H
#define PARTICLE_GUN_H

#include <nodes/2d/2d_entity.h>
#include <source/particle/p_bullet.h>

class PARTICLE_gun {
    public:
        PARTICLE_gun(Transform* transform, Mesh* mesh, Material* material, PARTICLE_bullet* bullet);
        ~PARTICLE_gun();

        Transform* get_transform();
        void set_transform(Transform* value);

        Mesh* get_mesh();
        void set_mesh(Mesh* value);

        Material* get_material();
        void set_material(Material* value);

        PARTICLE_bullet* get_bullet();
        void set_bullet(PARTICLE_bullet* value);

        void Execute();
        void Display();
        
    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        Attribute* attribute;

        PARTICLE_bullet* bullet;

        Box_hit* box_hit;
};

#endif