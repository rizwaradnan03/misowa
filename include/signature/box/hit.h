#pragma once

#include <cstdint>
#include <signature/attribute.h>
#include <graphics/transform.h>
#include <graphics/transform.h>
#include <engine/shader.h>

class Box_hit {
    public:
        void action(Transform* transform, Shader* shader, Attribute* attribute);
};