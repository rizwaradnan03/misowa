#ifndef PARTICLE_BULLET_H
#define PARTICLE_BULLET_H

#include <nodes/2d/2d_entity.h>
#include <vector>
#include <glad/glad.h>
#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>
#include <signature/box/box_hit.h>
#include <signature/st_attribute.h>
#include <namespace/n_physic.h>

struct Target {
    float x;
    float y;
};

class PARTICLE_bullet: public Entity {
    public:
        PARTICLE_bullet(Transform* transform, Mesh* mesh, Material* material, Target target);
        ~PARTICLE_bullet();

        Transform* get_transform();
        void set_transform(Transform* value);

        Mesh* get_mesh();
        void set_mesh(Mesh* value);

        Material* get_material();
        void set_material(Material* value);
        
        Attribute* get_attribute();
        void set_attribute(Attribute* value);
        
        Box_hit* get_box_hit();
        void set_box_hit(Box_hit* value);

        Target get_target();
        void set_target(Target value);

        void Execute(const std::vector<Body*>& objects);
        void Display();
        
    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        Attribute* attribute;

        Box_hit* box_hit;

        Target target;
};

#endif