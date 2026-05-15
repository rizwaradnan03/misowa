#pragma once

#include <source/world/player.h>
#include <nodes/body/body.h>
#include <nodes/body/static.h>
#include <namespace/rule.h>

class RT_World {
    public:
        void Init(std::string type);
        void Start();

        Player* get_player();
        void set_player(Player* value);

        std::vector<Body*> get_objects();
        void set_objects(std::vector<Body*> value);

    private:
        Player* player;
        std::vector<Body*> objects;
        
};

extern RT_World* RTW;