#pragma once

#include <vector>
#include <source/world/player.h>
#include <nodes/body/body.h>
#include <nodes/body/body_static.h>
#include <namespace/rule.h>
#include <singleton/g_action.h>
#include <graphics/transform.h>
#include <signature/attribute.h>
#include <engine/shader.h>
#include <nodes/gui/gui.h>
#include <nodes/entity.h>

class RT_World {
    public:
        void Init(std::string type);
        void Start();

        Player* get_player();
        void set_player(Player* value);

        std::vector<Body*> get_objects();
        void set_objects(std::vector<Body*> value);
        void set_push_object(Body* value);
        
        std::vector<Gui*> get_guis();
        void set_guis(std::vector<Gui*> value);
        void set_push_gui(Gui* value);

        void check_event();
        void check_event_hit();

    private:
        Player* player;
        std::vector<Body*> objects;
        std::vector<Gui*> guis;
};

extern RT_World* RTW;