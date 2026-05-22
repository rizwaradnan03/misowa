#pragma once

#include <graphics/transform.h>
#include <graphics/mesh.h>
#include <graphics/material.h>

class Gui {
    public:
        Gui(Transform* transform, Mesh* mesh, Material* material);
        
        virtual Transform* get_transform();
        virtual void set_transform(Transform* value);

        virtual Mesh* get_mesh();
        virtual void set_mesh(Mesh* value);

        virtual Material* get_material();
        virtual void set_material(Material* value);

        virtual void Execute();

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;
};