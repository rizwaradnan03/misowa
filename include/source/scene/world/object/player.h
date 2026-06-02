#ifndef OBJECT_PLAYER_H
#define OBJECT_PLAYER_H

#include <vector>
#include <cstdint>
#include <string>
#include <glad/glad.h>
#include <nodes/body/body_dynamic.h>
#include <namespace/n_input.h>
#include <namespace/n_default.h>
#include <namespace/n_physic.h>
#include <namespace/n_color.h>
#include <graphics/g_mesh.h>
#include <graphics/g_transform.h>
#include <graphics/g_material.h>
#include <nodes/2d/2d_camera.h>
#include <engine/e_movement.h>
#include <signature/st_attribute.h>
#include <signature/st_depth.h>
#include <signature/box/box_hit.h>
#include <signature/st_mouse.h>
#include <nodes/gui/gui_container.h>
#include <singleton/g_player.h>
#include <nodes/2d/2d_entity.h>

class Player: public BODY_Dynamic {
    public:
        Player(Transform* transform, Mesh* mesh, Material* material, Trait* trait);
        ~Player();
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

        Trait* get_trait();
        void set_trait(Trait* value);
        
        Depth* get_depth();
        void set_depth(Depth* value);

        Box_hit* get_box_hit();
        void set_box_hit(Box_hit* value);

        std::string* get_select_item();
        void set_select_item(std::string* value);

        Entity* get_holded_right();
        void set_holded_right(Entity* value);

        Entity* get_holded_left();
        void set_holded_left(Entity* value);

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

        Trait* trait;

        Attribute* attribute;
        Depth* depth;

        Box_hit* box_hit;

        std::string* select_item;

        Entity* holded_right;
        Entity* holded_left;

        std::vector<GUI_container*> gui_containers;
};

extern Player* G_OBJECT_player;

#endif