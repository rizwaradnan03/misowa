#pragma once

#include <cstdint>
#include <string>
#include <nodes/body/dynamic.h>
#include <glad/glad.h>
#include <namespace/input.h>
#include <namespace/default.h>
#include <namespace/physic.h>
#include <namespace/color.h>
#include <graphics/mesh.h>
#include <graphics/transform.h>
#include <graphics/material.h>
#include <nodes/camera.h>

class Player: public BODY_Dynamic {
    public:
        Player(float x, float y, float w, float h);
        void Run(const std::vector<Body*>& objects);
        void Display() override;
        
        void movement() override;;

        void physic(const std::vector<Body*>& objects);
        void object_collide(const std::vector<Body*>& objects);

        void trigger_change_position();

        Transform* get_transform() override;
        void set_transform(Transform* value) override;

        Mesh* get_mesh() override;
        void set_mesh(Mesh* value) override;

        Material* get_material() override;
        void set_material(Material* value) override;
        
        Camera* get_camera();
        void set_camera(Camera* value);

        void camera_alligner();

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;
        Camera* camera;
};