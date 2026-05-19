#include <render_type/world.h>
#include <iostream>

RT_World* RTW = nullptr;

void RT_World::Init(std::string type){
    std::vector<Body*> obj_to_push;
    
    if(type == "MAIN"){
        float x_val = 120;
        float y_val = 120;

        while(y_val < 240){
            while(x_val < 300){
                BODY_Static* st = new BODY_Static(x_val, y_val, 30.0f, 30.0f);
                obj_to_push.push_back(st);

                x_val += 30;
            }

            x_val = 120;
            y_val += 30;
        }
    }
    
    this->set_objects(obj_to_push);
    
    Player* p = new Player(0.0f, 0.0f, 30.0f, 30.0f);
    this->set_player(p);
}

Player* RT_World::get_player(){
    return this->player;
}

void RT_World::set_player(Player* value){
    this->player = value;
}

void RT_World::Start(){
    this->get_player()->Run(this->get_objects());
    for(int i = 0;i < this->get_objects().size();i++){
        this->get_objects()[i]->Run(this->get_objects());
    }
    
}

std::vector<Body*> RT_World::get_objects(){
    return this->objects;
}

void RT_World::set_objects(std::vector<Body*> value){
    this->objects = value;
}