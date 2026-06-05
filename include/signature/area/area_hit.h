#ifndef SIGNATURE_AREA_HIT
#define SIGNATURE_AREA_HIT

#include <config/c_pch.h>
#include <singleton/g_action.h>

class Area_Hit {
    public:
        Area_Hit(int32_t* damage, float x, float y, float w, float h);

        int32_t* get_damage();
        void set_damage(int32_t* value);

        float get_x();
        void set_x(float value);

        float get_y();
        void set_y(float value);

        float get_w();
        void set_w(float value);

        float get_h();
        void set_h(float value);

    private:
        int32_t* damage;
        float x, y, w, h;
};

#endif