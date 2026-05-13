#pragma once

#include <string>

namespace input {
    std::string* just_pressed();
    std::string* just_released();

    std::string* continuous_pressed();
}