#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include <nodes/body/body_dynamic.h>
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
#include <signature/attribute.h>
#include <signature/depth.h>
#include <signature/box/box_hit.h>
#include <signature/mouse.h>
#include <nodes/gui/gui_container.h>

class Player: public BODY_Dynamic {
    public:
        Player(Transform* transform, Mesh* mesh, Material* material);
        void Run(const std::vector<Body*>& objects);
        void Display() override;
        
        Transform* get_transform() override;
        void set_transform(Transform* value) override;

        Mesh* get_mesh() override;
        void set_mesh(Mesh* value) override;
        
        Material* get_material() override;
        void set_material(Material* value) override;
        
        Movement* get_movement();
        void set_movement(Movement* value);
        
        Camera* get_camera();
        void set_camera(Camera* value);

        Mouse* get_mouse();
        void set_mouse(Mouse* value);

        Attribute* get_attribute();
        void set_attribute(Attribute* value);
        
        Depth* get_depth();
        void set_depth(Depth* value);

        Box_hit* get_box_hit();
        void set_box_hit(Box_hit* value);

        std::vector<GUI_container*> get_gui_containers();
        void set_gui_containers(std::vector<GUI_container*> value);
        void set_push_gui_containers(GUI_container* value);

        void physic(const std::vector<Body*>& objects);
        void object_collide(const std::vector<Body*>& objects);
        void camera_alligner();
        void hit_checker();

    private:
        Transform* transform;
        
        Mesh* mesh;
        Material* material;
        Movement* movement;
        
        Camera* camera;
        Mouse* mouse;

        Attribute* attribute;
        Depth* depth;

        Box_hit* box_hit;

        std::vector<GUI_container*> gui_containers;
};