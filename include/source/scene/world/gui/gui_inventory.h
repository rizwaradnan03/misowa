#ifndef GUI_GUI_INVENTORY_H
#define GUI_GUI_INVENTORY_H

#include <config/c_pch.h>
#include <dto/dto_poleset.h>
#include <dto/dto_gui_item.h>
#include <namespace/n_default.h>
#include <namespace/n_identifier.h>
#include <namespace/n_input.h>
#include <namespace/n_color.h>
#include <nodes/gui/gui.h>
#include <nodes/gui/gui_container.h>
#include <nodes/particle/p_item.h>
#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>
#include <source/scene/world/object/player.h>

class GUI_item;

class GUI_inventory: public GUI_container {
    public:
        GUI_inventory(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet);
        ~GUI_inventory();
        
        std::string get_id() override;
        void set_id(std::string value) override;

        Transform* get_transform() override;
        void set_transform(Transform* value) override;

        Mesh* get_mesh() override;
        void set_mesh(Mesh* value) override;

        Material* get_material() override;
        void set_material(Material* value) override;

        std::string* get_select_item();
        void set_select_item(std::string* value);

        float get_pole_x() override;
        void set_pole_x(float value) override;
        
        float get_pole_y() override;
        void set_pole_y(float value) override;

        std::vector<GUI_item*> get_nodes() override;
        void set_nodes(std::vector<GUI_item*> value) override;

        void Execute(Transform* transform) override;

    private:
        std::string id;
        Transform* transform;
        Mesh* mesh;
        Material* material;

        std::string* select_item;

        float pole_x, pole_y;

        std::vector<GUI_item*> nodes;
};

extern GUI_inventory* G_GUI_inventory;

#endif