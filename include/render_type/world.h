#pragma once

#include <vector>
#include <source/world/player.h>
#include <nodes/body/body.h>
#include <nodes/body/static.h>
#include <namespace/rule.h>
#include <singleton/action.h>
#include <graphics/transform.h>
#include <signature/attribute.h>
#include <engine/shader.h>

class RT_World {
    public:
        void Init(std::string type);
        void Start();

        Player* get_player();
        void set_player(Player* value);

        std::vector<Body*> get_objects();
        void set_objects(std::vector<Body*> value);

        void check_event();
        void check_event_hit();

    private:
        Player* player;
        std::vector<Body*> objects;
};

extern RT_World* RTW;