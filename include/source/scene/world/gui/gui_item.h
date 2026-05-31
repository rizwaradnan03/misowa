#pragma once

#include <nodes/gui/gui_click.h>
#include <string>
#include <singleton/g_player.h>

class GUI_item: public GUI_click {
    public:
        GUI_item(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet, std::string* item);
        ~GUI_item();
        
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

        std::string* get_item();
        void set_item(std::string* value);

        virtual void hit_action();

        virtual void Execute(Transform* transform) override;

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        std::string* item;
        
        float pole_x, pole_y;
};