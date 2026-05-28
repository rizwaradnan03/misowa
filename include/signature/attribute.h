#pragma once

#include <cstdint>
#include <engine/shader.h>
#include <graphics/transform.h>
#include <glad/glad.h>
#include <namespace/color.h>

class Attribute {
    public:
        Attribute(int32_t health);

        int32_t get_health();
        void set_health(int32_t value);

        uint8_t get_amount();
        void set_amount(uint8_t value);

        void hit(int32_t* damage, Transform* transform, Shader* shader);
        void Execute(Transform* transform, Shader* shader);
    private:
        int32_t health;
        uint8_t amount;
};