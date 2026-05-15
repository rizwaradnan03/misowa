#pragma once

#include <glad/glad.h>
#include <vector>
#include <cstdint>
#include <graphics/mesh.h>
#include <graphics/transform.h>
#include <graphics/material.h>
#include <namespace/color.h>

class Body {
    public:
        Body(int32_t x, int32_t y, int32_t w, int32_t h);
        virtual void Run(const std::vector<Body*>& objects);
        virtual void Display();
        
        virtual void physic(const std::vector<Body*>& objects);
        virtual void object_collide(const std::vector<Body*>& objects);

        virtual void trigger_change_position();

        virtual Transform* get_transform();
        virtual void set_transform(Transform* value);

        virtual Mesh* get_mesh();
        virtual void set_mesh(Mesh* value);

        virtual Material* get_material();
        virtual void set_material(Material* value);

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;
};