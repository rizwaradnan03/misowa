#ifndef GUI_GUI_CONTAINER_H
#define GUI_GUI_CONTAINER_H

#include <config/c_pch.h>
#include <dto/dto_poleset.h>
#include <namespace/n_identifier.h>
#include <nodes/gui/gui.h>
#include <nodes/particle/p_item.h>
#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>

class GUI_item;

class GUI_container: public Gui {
    public:
        GUI_container(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet);
        ~GUI_container();
        
        virtual std::string get_id() override;
        virtual void set_id(std::string value) override;

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

        virtual std::vector<GUI_item*> get_nodes();
        virtual void set_nodes(std::vector<GUI_item*> value);

        virtual void Execute(Transform* transform);

    private:
        std::string id;

        Transform* transform;
        Mesh* mesh;
        Material* material;

        float pole_x, pole_y;

        std::vector<GUI_item*> nodes;
};

#endif