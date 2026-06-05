#ifndef SIGNATURE_COLLIDE_MASK_H
#define SIGNATURE_COLLIDE_MASK_H

#include <config/c_pch.h>

class CollideMask {
    public:
        CollideMask(std::vector<uint8_t> mask);

        std::vector<uint8_t> get_mask();
        void set_mask(std::vector<uint8_t> value);

    private:
        std::vector<uint8_t> mask;
};

#endif