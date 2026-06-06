#ifndef GUI_GUI_DRAG_G
#define GUI_GUI_DRAG_G

#include <nodes/gui/gui.h>
#include <dto/dto_poleset.h>
#include <namespace/n_input.h>
#include <namespace/n_identifier.h>
#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>

class GUI_drag: public Gui {
    public:
        GUI_drag(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet);
        
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

        virtual void drag_action();

        virtual void Execute(Transform* transform) override;

    private:
        std::string id;

        Transform* transform;
        Mesh* mesh;
        Material* material;

        float pole_x, pole_y;
};

#endif