#pragma once

#include <vector>
#include <glad/glad.h>
#include <graphics/transform.h>
#include <graphics/mesh.h>
#include <graphics/material.h>

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

        virtual void Execute(const std::vector<Body*>& objects);
        virtual void Display();

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;
};