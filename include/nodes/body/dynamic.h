#pragma once

#include <glad/glad.h>
#include <nodes/body/body.h>
#include <cstdint>
#include <vector>

class BODY_Dynamic: public Body {
    public:
        BODY_Dynamic(float* verticle, int32_t sz);
        virtual void Run() override;
        virtual void Display() override;
        
        virtual void movement();

        virtual void update_vbo() override;

        virtual std::vector<float> get_verticle() override;
        virtual void set_verticle(std::vector<float> value) override;

        virtual unsigned int* get_indices() override;
        virtual void set_indices(unsigned int* value) override;

        virtual int32_t get_verticle_count() override;
        virtual void set_verticle_count(int32_t value) override;

        virtual int32_t get_indices_count() override;
        virtual void set_indices_count(int32_t value) override;


    private:
        std::vector<float> verticle;
        unsigned int* indices;

        int32_t verticle_count;
        int32_t indices_count;

        unsigned int VAO, VBO, EBO;
};