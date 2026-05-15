#pragma once

#include <engine/shader.h>

class Material {
    public:
        Material( float r, float g, float b, float a);
        void Execute(int32_t x, int32_t y);

        Shader* get_shader();
        void set_shader(Shader* value);

        float get_r();
        void set_r(float value);

        float get_g();
        void set_g(float value);

        float get_b();
        void set_b(float value);

        float get_a();
        void set_a(float value);

    private:
        Shader* shader;
        float r, g, b, a;
};