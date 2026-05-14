#pragma once

#include <glad/glad.h>
#include <vector>
#include <cstdint>
#include <vector>

class Body {
    public:
        Body(float* verticle, int32_t sz);
        virtual void Run();
        virtual void Display();

        virtual void update_vbo();

        virtual std::vector<float> get_verticle();
        virtual void set_verticle(std::vector<float> value);

        virtual unsigned int* get_indices();
        virtual void set_indices(unsigned int* value);

        virtual int32_t get_verticle_count();
        virtual void set_verticle_count(int32_t value);

        virtual int32_t get_indices_count();
        virtual void set_indices_count(int32_t value);

    private:
        std::vector<float> verticle;
        unsigned int* indices;

        // int32_t 
        int32_t verticle_count;
        int32_t indices_count;

        unsigned int VAO, VBO, EBO;
};