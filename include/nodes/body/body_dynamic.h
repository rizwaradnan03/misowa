#pragma once

#include <cstdint>
#include <string>
#include <nodes/body/body.h>
#include <glad/glad.h>
#include <namespace/input.h>
#include <namespace/default.h>
#include <namespace/physic.h>
#include <namespace/color.h>
#include <graphics/mesh.h>
#include <graphics/transform.h>
#include <graphics/material.h>
#include <nodes/camera.h>
#include <engine/movement.h>
#include <signature/trait.h>

class BODY_Dynamic: public Body {
    public:
        BODY_Dynamic(Transform* transform, Mesh* mesh, Material* material, Trait* trait);
        void Execute(const std::vector<Body*>& objects);
        void Display() override;
        
        void physic(const std::vector<Body*>& objects);
        void object_collide(const std::vector<Body*>& objects);

        Transform* get_transform() override;
        void set_transform(Transform* value) override;

        Mesh* get_mesh() override;
        void set_mesh(Mesh* value) override;

        Material* get_material() override;
        void set_material(Material* value) override;

        Trait* get_trait() override;
        void set_trait(Trait* value) override;
        
        Movement* get_movement();
        void set_movement(Movement* value);

        Camera* get_camera();
        void set_camera(Camera* value);

        void camera_alligner();

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        Trait* trait;

        Movement* movement;

        Camera* camera;
};