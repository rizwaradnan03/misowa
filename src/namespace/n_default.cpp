#include <namespace/n_default.h>

namespace dft {
    int32_t PLAYER_speed = 20;
    float PLAYER_MOVE_PER_FRAME = 0.005f;

    uint8_t entity_width = 30;
    uint8_t entity_height = 30;

    float calc_displacement(){
        return PLAYER_MOVE_PER_FRAME * PLAYER_speed;
    }
};