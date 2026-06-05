#ifndef SINGLETON_SYSTEM_H
#define SINGLETON_SYSTEM_H

#include <config/c_pch.h>
#include <render_type/rt_world.h>
#include <render_type/rt_gui.h>
#include <engine/e_shader.h>

enum R_TYPE {
    WORLD,
    GUI
};

class System {
    public:
        void change_screen(R_TYPE rt, std::string scr);
        R_TYPE* get_render_type();

        Shader* get_shader();
        void set_shader(Shader* value);

    private:
        R_TYPE* render_type;
        Shader* shader;
};

extern System* G_SINGLETON_system;

#endif