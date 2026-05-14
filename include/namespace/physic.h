#pragma once

#include <nodes/body/body.h>
#include <string>
#include <utility>

namespace physic {
    std::pair<bool, std::string*> check_collide(Body* me, Body* target);
};