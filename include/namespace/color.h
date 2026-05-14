#pragma once

#include <utility>
#include <vector>
#include <string>

namespace color {
    enum C_Type {
        RED,
        GREEN,
        BLUE,
        WHITE
    };

    extern std::vector<std::pair<C_Type, std::vector<float>>> SYS_Color;
    std::vector<float> find_rgba_color_by_name(C_Type col);
};