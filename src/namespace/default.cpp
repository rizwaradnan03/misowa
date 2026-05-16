#include <namespace/default.h>

namespace dft {
    int32_t PLAYER_speed = 2;
    float PLAYER_MOVE_PER_FRAME = 0.0005;

    float calc_displacement(){
        return PLAYER_MOVE_PER_FRAME * PLAYER_speed;
    }

};