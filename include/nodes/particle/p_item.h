#ifndef PARTICLE_ITEM_H
#define PARTICLE_ITEM_H

#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>
#include <nodes/2d/2d_entity.h>

class PARTICLE_item: public Entity {
    public:
        PARTICLE_item(Transform* transform, Mesh* mesh, Material* material);
        ~PARTICLE_item();

        Transform* get_transform();
        void set_transform(Transform* value);

        Mesh* get_mesh();
        void set_mesh(Mesh* value);

        Material* get_material();
        void set_material(Material* value);

        void Execute();
        void Display();
        
    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;
};

#endif