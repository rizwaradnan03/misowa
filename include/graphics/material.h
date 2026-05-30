#pragma once

#include <engine/shader.h>
#include <graphics/transform.h>

class Material {
    public:
        Material(float r, float g, float b, float a);
        ~Material();
        void Execute(Transform* transform);

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