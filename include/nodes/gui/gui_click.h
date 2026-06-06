#ifndef GUI_GUI_CLICK_H
#define GUI_GUI_CLICK_H

#include <dto/dto_poleset.h>
#include <namespace/n_input.h>
#include <namespace/n_identifier.h>
#include <nodes/gui/gui.h>
#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>
#include <singleton/g_action.h>

class GUI_click: public Gui {
    public:
        GUI_click(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet);
        ~GUI_click();
        
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

        virtual void hit_action();

        virtual void Execute(Transform* transform) override;

    private:
        std::string id;

        Transform* transform;
        Mesh* mesh;
        Material* material;

        float pole_x, pole_y;
};

#endif