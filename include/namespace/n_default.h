#ifndef NAMESPACE_DEFAULT_H
#define NAMESPACE_DEFAULT_H

#include <config/c_pch.h>

namespace dft {
    extern int32_t PLAYER_speed;
    extern float PLAYER_MOVE_PER_FRAME;

    extern uint8_t entity_width;
    extern uint8_t entity_height;

    float calc_displacement();
};

#endif