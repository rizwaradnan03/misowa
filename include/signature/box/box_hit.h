#ifndef SIGNATURE_BOX_HIT
#define SIGNATURE_BOX_HIT

#include <config/c_pch.h>
#include <signature/st_attribute.h>
#include <graphics/g_transform.h>
#include <graphics/g_transform.h>
#include <engine/e_shader.h>

class Box_hit {
    public:
        void action(int32_t* damage, Transform* transform, Shader* shader, Attribute* attribute);
};

#endif