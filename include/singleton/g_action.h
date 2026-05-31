#ifndef SINGLETON_ACTION_H
#define SINGLETON_ACTION_H

#include <vector>
#include <signature/area/area_hit.h>

class Area_Hit;

class SINGLETON_action {
    public:
        std::vector<Area_Hit*> get_action_object_hit();
        void set_action_object_hit(std::vector<Area_Hit*> value);
        void set_push_action_object_hit(Area_Hit* value);

    private:
        std::vector<Area_Hit*> action_object_hit;
};

extern SINGLETON_action* G_SINGLETON_action;

#endif