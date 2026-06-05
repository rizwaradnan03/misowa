#ifndef NAMESPACE_INPUT_H
#define NAMESPACE_INPUT_H

#include <config/c_pch.h>
#include <namespace/n_system.h>
#include <singleton/g_gl.h>

class Player;

namespace input {
    std::string* just_pressed();
    std::string* just_released();
    std::string* continuous_pressed();

    std::string* mouse_pressed();
    std::pair<float, float> mouse_position();

    std::pair<float, float> mouse_position_with_player_as_pole();

    bool space_pressed();
};

#endif