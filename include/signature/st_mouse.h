#ifndef SIGNATURE_MOUSE_H
#define SIGNATURE_MOUSE_H

#include <utility>
#include <singleton/g_action.h>
#include <namespace/n_input.h>

class Mouse {
    public:
        Mouse();

        std::pair<float, float> get_position();
        void Execute();
};

#endif