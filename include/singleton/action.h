#pragma once

#include <vector>
#include <signature/area/hit.h>

class Area_Hit;

class SINGLETON_action {
    public:
        std::vector<Area_Hit*> get_action_hit();
        void set_action_hit(std::vector<Area_Hit*> value);
        void set_push_action_hit(Area_Hit* value);

    private:
        std::vector<Area_Hit*> action_hit;
};

extern SINGLETON_action* G_SINGLETON_action;