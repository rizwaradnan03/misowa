#ifndef BODY_BODY_H
#define BODY_BODY_H

#include <config/c_pch.h>
#include <graphics/g_mesh.h>
#include <graphics/g_transform.h>
#include <graphics/g_material.h>
#include <namespace/n_color.h>
#include <signature/box/box_hit.h>
#include <signature/st_trait.h>
#include <signature/st_attribute.h>
#include <nodes/2d/2d_entity.h>

class Body: public Entity {
    public:
        Body(Transform* transform, Mesh* mesh, Material* material, Trait* trait);
        ~Body();

        virtual void Execute(const std::vector<Body*>& objects);
        virtual void Display();
        
        virtual void physic(const std::vector<Body*>& objects);
        virtual void object_collide(const std::vector<Body*>& objects);

        virtual Transform* get_transform();
        virtual void set_transform(Transform* value);

        virtual Mesh* get_mesh();
        virtual void set_mesh(Mesh* value);

        virtual Material* get_material();
        virtual void set_material(Material* value);

        virtual Trait* get_trait();
        virtual void set_trait(Trait* value);

        virtual Attribute* get_attribute();
        virtual void set_attribute(Attribute* value);

        virtual Box_hit* get_box_hit();
        virtual void set_box_hit(Box_hit* value);

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        Attribute* attribute;
        Trait* trait;

        Box_hit* box_hit;
};

#endif