#include <render_type/world.h>
#include <iostream>

RT_World* RTW = nullptr;

void RT_World::Init(std::string type){
    std::vector<Body*> obj_to_push;
    
    if(type == "MAIN"){
        float x_val = -1.0f;
        float y_val = -1.0f;

        while(y_val < 0.0f){
            while(x_val < 1.0f){
                float vertx[] = {
                    x_val, y_val + 0.5f,
                    x_val + 0.5f, y_val + 0.5f,
                    x_val + 0.5f, y_val,
                    x_val, y_val
                };

                Body* obj = new BODY_Static(0, 0, 30, 30);
                obj_to_push.push_back(obj);

                x_val += 0.5f;
                break;
            }

            x_val = -2.0f;
            y_val += 0.5f;
            break;
        }
    }
    
    // this->set_objects(obj_to_push);
    
    Player* p = new Player(0, 0, 30, 30);
    this->set_player(p);
}

Player* RT_World::get_player(){
    return this->player;
}

void RT_World::set_player(Player* value){
    this->player = value;
}

void RT_World::Start(){
    this->get_player()->Run(this->objects);
    // for(int i = 0;i < this->get_objects().size();i++){
    //     this->get_objects()[i]->Run(this->get_objects());
    // }
}

std::vector<Body*> RT_World::get_objects(){
    return this->objects;
}

void RT_World::set_objects(std::vector<Body*> value){
    this->objects = value;
}