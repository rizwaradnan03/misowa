#ifndef PARTICLE_ITEM_H
#define PARTICLE_ITEM_H

#include <config/c_pch.h>
#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>
#include <nodes/2d/2d_entity.h>

class PARTICLE_item: public Entity {
    public:
        PARTICLE_item(Transform* transform, Mesh* mesh, Material* material);
        ~PARTICLE_item();

        virtual Transform* get_transform() override;
        virtual void set_transform(Transform* value) override;

        virtual Mesh* get_mesh() override;
        virtual void set_mesh(Mesh* value) override;

        virtual Material* get_material() override;
        virtual void set_material(Material* value) override;

        virtual void Execute();
        virtual void Display() override;
        
    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;
};

#endif