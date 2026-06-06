#ifndef BODY_BODY_DYNAMIC_H
#define BODY_BODY_DYNAMIC_H

#include <config/c_pch.h>
#include <nodes/body/body.h>
#include <namespace/n_input.h>
#include <namespace/n_default.h>
#include <namespace/n_physic.h>
#include <namespace/n_color.h>
#include <namespace/n_identifier.h>
#include <graphics/g_mesh.h>
#include <graphics/g_transform.h>
#include <graphics/g_material.h>
#include <nodes/2d/2d_camera.h>
#include <engine/e_movement.h>
#include <signature/st_trait.h>

class BODY_Dynamic: public Body {
    public:
        BODY_Dynamic(Transform* transform, Mesh* mesh, Material* material, Trait* trait);
        ~BODY_Dynamic();
        
        std::string get_id();
        void set_id(std::string value);

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
        void Execute(const std::vector<Body*>& objects);
        void Display() override;

    private:
        std::string id;

        Transform* transform;
        Mesh* mesh;
        Material* material;

        Trait* trait;

        Movement* movement;

        Camera* camera;
};

#endif