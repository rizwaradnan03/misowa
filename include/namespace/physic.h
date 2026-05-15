#pragma once

#include <graphics/mesh.h>
#include <string>
#include <utility>

namespace physic {
    std::pair<bool, std::string*> check_collide(Mesh* me, Mesh* target);
};