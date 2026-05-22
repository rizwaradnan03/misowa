#pragma once

#include <vector>
#include <nodes/gui/gui.h>
#include <nodes/gui/gui_container.h>
#include <graphics/transform.h>
#include <graphics/mesh.h>
#include <graphics/material.h>

class GUI_inventory: public GUI_container {
    public:
        GUI_inventory(Transform* transform, Mesh* mesh, Material* material);
        
        virtual Transform* get_transform() override;
        virtual void set_transform(Transform* value) override;

        virtual Mesh* get_mesh() override;
        virtual void set_mesh(Mesh* value) override;

        virtual Material* get_material() override;
        virtual void set_material(Material* value) override;

        virtual std::vector<Gui*> get_nodes();
        virtual void set_nodes(std::vector<Gui*> value);

        virtual void Execute() override;

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        std::vector<Gui*> nodes;
};