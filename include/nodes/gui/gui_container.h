#pragma once

#include <vector>
#include <nodes/gui/gui.h>
#include <graphics/transform.h>
#include <graphics/mesh.h>
#include <graphics/material.h>
#include <dto/dto_poleset.h>

class GUI_container: public Gui {
    public:
        GUI_container(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet);
        
        virtual Transform* get_transform() override;
        virtual void set_transform(Transform* value) override;

        virtual Mesh* get_mesh() override;
        virtual void set_mesh(Mesh* value) override;

        virtual Material* get_material() override;
        virtual void set_material(Material* value) override;

        virtual float get_pole_x() override;
        virtual void set_pole_x(float value) override;

        virtual float get_pole_y() override;
        virtual void set_pole_y(float value) override;

        virtual std::vector<Gui*> get_nodes();
        virtual void set_nodes(std::vector<Gui*> value);

        virtual void Execute(Transform* transform);

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        float pole_x, pole_y;

        std::vector<Gui*> nodes;
};