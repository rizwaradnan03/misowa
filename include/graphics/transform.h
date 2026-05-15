#pragma once

#include <cstdint>

class Transform {
    public:
        Transform(int32_t x, int32_t y, int32_t w, int32_t h);

        int32_t get_x();
        void set_x(int32_t value);

        int32_t get_y();
        void set_y(int32_t value);

        int32_t get_w();
        void set_w(int32_t value);

        int32_t get_h();
        void set_h(int32_t value);
    
    private:
        int32_t x, y, w, h;
};