#ifndef BODY_BODY_STATIC_H
#define BODY_BODY_STATIC_H

#include <config/c_pch.h>
#include <nodes/body/body.h>
#include <engine/e_shader.h>
#include <namespace/n_color.h>
#include <namespace/n_default.h>
#include <graphics/g_mesh.h>
#include <graphics/g_transform.h>
#include <graphics/g_material.h>
#include <signature/st_trait.h>

class BODY_Static: public Body {
    public:
        BODY_Static(Transform* transform, Mesh* mesh, Material* material, Trait* trait);
        ~BODY_Static();
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

        virtual Trait* get_trait();
        virtual void set_trait(Trait* value);

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        Trait* trait;
};

#endif