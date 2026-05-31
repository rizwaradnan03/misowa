#ifndef NAMESPACE_PHYSIC_H
#define NAMESPACE_PHYSIC_H

#include <graphics/g_mesh.h>
#include <string>
#include <utility>
#include <nodes/2d/2d_entity.h>

namespace physic {
    std::pair<bool, std::string*> check_collide(Mesh* me, Mesh* target);
    void move_y_and_x_defined_stuff(Entity* entity, float xTarget, float yTarget);
};

#endif