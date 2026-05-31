#ifndef GUI_GUI_DRAG_G
#define GUI_GUI_DRAG_G

#include <nodes/gui/gui.h>
#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>
#include <dto/dto_poleset.h>
#include <namespace/n_input.h>

class GUI_drag: public Gui {
    public:
        GUI_drag(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet);
        
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
        Transform* transform;
        Mesh* mesh;
        Material* material;

        float pole_x, pole_y;
};

#endif