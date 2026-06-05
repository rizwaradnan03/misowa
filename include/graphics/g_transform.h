#ifndef GRAPHIC_TRANSFORM_H
#define GRAPHIC_TRANSFORM_H

#include <config/c_pch.h>

class Transform {
    public:
        Transform(float x, float y, float w, float h);

        float get_x();
        void set_x(float value);

        float get_y();
        void set_y(float value);

        float get_w();
        void set_w(float value);

        float get_h();
        void set_h(float value);
    
    private:
        float x, y, w, h;
};

#endif