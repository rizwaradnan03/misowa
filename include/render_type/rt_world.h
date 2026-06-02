#ifndef RENDER_TYPE_WORLD_H
#define RENDER_TYPE_WORLD_H

#include <vector>
#include <source/scene/world/object/player.h>
#include <nodes/body/body.h>
#include <nodes/body/body_static.h>
#include <namespace/n_rule.h>
#include <singleton/g_action.h>
#include <graphics/g_transform.h>
#include <signature/st_attribute.h>
#include <engine/e_shader.h>
#include <nodes/2d/2d_entity.h>
#include <source/scene/world/gui/gui_inventory.h>
#include <dto/dto_poleset.h>
#include <source/scene/world/gui/gui_item.h>
#include <nodes/2d/2d_entity.h>

class RT_World {
    public:
        void Init(std::string type);
        void Start();

        Player* get_player();
        void set_player(Player* value);

        std::vector<Body*> get_objects();
        void set_objects(std::vector<Body*> value);
        void set_push_object(Body* value);
        
        std::vector<Entity*> get_particles();
        void set_particles(std::vector<Entity*> value);
        void set_push_particle(Entity* value);

        void check_event();
        void check_event_object_hit();

    private:
        Player* player;
        std::vector<Body*> objects;
        std::vector<Entity*> particles;
};

extern RT_World* RTW;

#endif