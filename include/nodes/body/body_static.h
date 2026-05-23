#pragma once

#include <glad/glad.h>
#include <nodes/body/body.h>
#include <cstdint>
#include <vector>
#include <engine/shader.h>
#include <namespace/color.h>
#include <namespace/default.h>
#include <graphics/mesh.h>
#include <graphics/transform.h>
#include <graphics/material.h>

class BODY_Static: public Body {
    public:
        BODY_Static(Transform* transform, Mesh* mesh, Material* material);
        virtual void Execute(const std::vector<Body*>& objects) override;
        virtual void Display() override;
        
        virtual void physic(const std::vector<Body*>& objects) override;
        virtual void object_collide(const std::vector<Body*>& objects) override;

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