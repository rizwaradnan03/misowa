#pragma once

#include <utility>
#include <singleton/g_action.h>
#include <namespace/input.h>

class Mouse {
    public:
        std::pair<double, double> get_position();
        void Execute();
};