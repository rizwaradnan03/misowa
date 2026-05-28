#pragma once

#include <utility>
#include <singleton/g_action.h>
#include <namespace/input.h>

class Mouse {
    public:
        Mouse();

        std::pair<float, float> get_position();
        void Execute();
};