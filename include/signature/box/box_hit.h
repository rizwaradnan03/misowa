#pragma once

#include <cstdint>
#include <signature/st_attribute.h>
#include <graphics/g_transform.h>
#include <graphics/g_transform.h>
#include <engine/e_shader.h>

class Box_hit {
    public:
        void action(int32_t* damage, Transform* transform, Shader* shader, Attribute* attribute);
};