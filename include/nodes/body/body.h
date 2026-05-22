#pragma once

#include <glad/glad.h>
#include <vector>
#include <cstdint>
#include <graphics/mesh.h>
#include <graphics/transform.h>
#include <graphics/material.h>
#include <namespace/color.h>
#include <signature/box/hit.h>
#include <signature/attribute.h>

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

        virtual Attribute* get_attribute();
        virtual void set_attribute(Attribute* value);

        virtual Box_hit* get_box_hit();
        virtual void set_box_hit(Box_hit* value);

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        Attribute* attribute;

        Box_hit* box_hit;
};