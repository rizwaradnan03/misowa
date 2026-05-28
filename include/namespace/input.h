#pragma once

#include <string>
#include <utility>
#include <singleton/g_gl.h>
#include <GLFW/glfw3.h>

namespace input {
    std::string* just_pressed();
    std::string* just_released();

    std::string* continuous_pressed();

    std::string* mouse_pressed();

    std::pair<float, float> mouse_position();
};