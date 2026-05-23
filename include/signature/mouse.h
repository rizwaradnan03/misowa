#pragma once

#include <utility>
#include <singleton/g_action.h>
#include <namespace/input.h>

class Mouse {
    public:
        Mouse();

        std::pair<double, double> get_position();
        void Execute();
};