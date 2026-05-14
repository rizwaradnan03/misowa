#include <render_type/world.h>
#include <iostream>

RT_World* RTW = nullptr;

void RT_World::Init(enum World_Type wt){
    
    if(wt == MAIN){
        float vert[] = {
            -0.1f, -0.1f,
            0.1f, -0.1f,
            0.1f, 0.1f,
            -0.1f, 0.1f,
        };
        
        Player* p = new Player(vert, 8);
        this->set_player(p);
    }
}

Player* RT_World::get_player(){
    return this->player;
}

void RT_World::set_player(Player* value){
    this->player = value;
}

void RT_World::Start(){
    this->get_player()->Run(this->objects);
}