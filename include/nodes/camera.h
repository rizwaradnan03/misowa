#pragma once

class Camera {
    public:
        Camera(float x, float y);

        float get_x();
        void set_x(float value);
        
        float get_y();
        void set_y(float value);

        void Execute();
        void update_position(float x, float y);

        float view[16];
        float projection[16];

    private:
        float x, y;
};