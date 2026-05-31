#ifndef GUI_GUI
#define GUI_GUI

#include <graphics/g_transform.h>
#include <graphics/g_mesh.h>
#include <graphics/g_material.h>
#include <nodes/2d/2d_entity.h>
#include <dto/dto_poleset.h>

class Gui: public Entity {
    public:
        Gui(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet);
        
        virtual Transform* get_transform();
        virtual void set_transform(Transform* value);

        virtual Mesh* get_mesh();
        virtual void set_mesh(Mesh* value);

        virtual Material* get_material();
        virtual void set_material(Material* value);

        virtual float get_pole_x();
        virtual void set_pole_x(float value);

        virtual float get_pole_y();
        virtual void set_pole_y(float value);

        virtual void Execute(Transform* transform);

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        float pole_x, pole_y;
};

#endif