#ifndef TWO_D_ENTITY_H
#define TWO_D_ENTITY_H

#include <vector>
#include <glad/glad.h>
#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>
#include <signature/box/box_hit.h>
#include <signature/st_attribute.h>

class Body;
class Transform;
class Mesh;
class Material;

class Entity {
    public:
        Entity(Transform* transform, Mesh* mesh, Material* material);

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

        virtual void Execute(const std::vector<Body*>& objects);
        virtual void Display();

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        Attribute* attribute;

        Box_hit* box_hit;
};

#endif