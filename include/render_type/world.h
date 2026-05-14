#pragma once

#include <source/world/player.h>
#include <nodes/body/body.h>

enum World_Type {
    MAIN,
    DUNGEON
};

class RT_World {
    public:
        void Init(enum World_Type wt);
        void Start();

        Player* get_player();
        void set_player(Player* value);

    private:
        Player* player;
        std::vector<Body*> objects;
        
};

extern RT_World* RTW;