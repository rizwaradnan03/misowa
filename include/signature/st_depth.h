#ifndef SIGNATURE_DEPTH_H
#define SIGNATURE_DEPTH_H

#include <chrono>
#include <signature/st_attribute.h>

class Depth {
    public:
        Depth();

        std::chrono::time_point<std::chrono::high_resolution_clock>* get_dive_time();
        void set_dive_time(std::chrono::time_point<std::chrono::high_resolution_clock>* value);

        int32_t get_oxygen_level();
        void set_oxygen_level(int32_t value);

        void calculate_long_dive(Attribute* attribute);
        void check_collide_with_water();
        void Execute(Attribute* attribute);

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock>* dive_time;
        int32_t oxygen_level;
};

#endif