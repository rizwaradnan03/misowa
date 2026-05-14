#pragma once

#include <glad/glad.h>
#include <nodes/body/body.h>
#include <cstdint>
#include <vector>
#include <engine/shader.h>
#include <namespace/color.h>
#include <namespace/default.h>
#include <namespace/input.h>

class BODY_Static: public Body {
    public:
        BODY_Static(float verticle[], int32_t sz);
        void Run() override;
        void Display() override;
        
        virtual void movement();

        void update_vbo() override;

        void set_renderer(color::C_Type color);

        std::vector<float> get_verticle() override;
        void set_verticle(std::vector<float> value) override;

        unsigned int* get_indices() override;
        void set_indices(unsigned int* value) override;

        int32_t get_verticle_count() override;
        void set_verticle_count(int32_t value) override;

        int32_t get_indices_count() override;
        void set_indices_count(int32_t value) override;

        Shader* get_shader();
        void set_shader(Shader* value);


    private:
        std::vector<float> verticle;
        unsigned int* indices;
        Shader* shader;

        int32_t verticle_count;
        int32_t indices_count;

        unsigned int VAO, VBO, EBO;
};