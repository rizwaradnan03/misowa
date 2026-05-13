#pragma once

#include <nodes/body/dynamic.h>
#include <glad/glad.h>
#include <cstdint>
#include <string>

class Player: public BODY_Dynamic {
    public:
        Player(float* verticle, int32_t sz);
        void Run() override;
        void Display() override;
        
        void movement() override;

        void update_shape() override;

        float* get_verticle() override;
        void set_verticle(float* value) override;

        unsigned int* get_indices() override;
        void set_indices(unsigned int* value) override;

        int32_t get_verticle_count() override;
        void set_verticle_count(int32_t value) override;

        int32_t get_indices_count() override;
        void set_indices_count(int32_t value) override;


    private:
        float* verticle;
        unsigned int* indices;

        int32_t verticle_count;
        int32_t indices_count;

        unsigned int VAO, VBO, EBO;
};