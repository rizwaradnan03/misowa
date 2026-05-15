#pragma once

#include <glad/glad.h>
#include <nodes/body/body.h>
#include <cstdint>
#include <vector>
#include <namespace/color.h>
#include <namespace/default.h>
#include <graphics/mesh.h>
#include <graphics/transform.h>
#include <graphics/material.h>

class BODY_Dynamic: public Body {
    public:
        BODY_Dynamic(int32_t x, int32_t y, int32_t w, int32_t h);
        virtual void Run(const std::vector<Body*>& objects) override;
        virtual void Display() override;
        
        virtual void movement();

        virtual void physic(const std::vector<Body*>& objects) override;
        virtual void object_collide(const std::vector<Body*>& objects) override;

        virtual void trigger_change_position() override;

        virtual Transform* get_transform() override;
        virtual void set_transform(Transform* value) override;

        virtual Mesh* get_mesh() override;
        virtual void set_mesh(Mesh* value) override;

        virtual Material* get_material();
        virtual void set_material(Material* value);

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;
};