#pragma once

#include <string>
#include <utility>
#include <singleton/gl.h>
#include <GLFW/glfw3.h>

namespace input {
    std::string* just_pressed();
    std::string* just_released();

    std::string* continuous_pressed();

    std::pair<double, double> mouse_position();
};