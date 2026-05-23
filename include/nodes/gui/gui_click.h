#pragma once

#include <nodes/gui/gui.h>

class GUI_click: public Gui {
    public:
        GUI_click(Transform* transform, Mesh* mesh, Material* material);
        
        virtual Transform* get_transform() override;
        virtual void set_transform(Transform* value) override;

        virtual Mesh* get_mesh() override;
        virtual void set_mesh(Mesh* value) override;

        virtual Material* get_material() override;
        virtual void set_material(Material* value) override;

        virtual void hit_action();

        virtual void Execute() override;

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;
};