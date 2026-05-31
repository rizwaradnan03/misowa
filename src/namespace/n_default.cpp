#include <namespace/n_default.h>

namespace dft {
    int32_t PLAYER_speed = 20;
    float PLAYER_MOVE_PER_FRAME = 0.005f;

    float calc_displacement(){
        return PLAYER_MOVE_PER_FRAME * PLAYER_speed;
    }

};