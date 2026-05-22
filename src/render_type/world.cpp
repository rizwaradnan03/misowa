#include <render_type/world.h>
#include <iostream>
#include <singleton/action.h>

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

std::vector<Body*> RT_World::get_objects(){
    return this->objects;
}

void RT_World::set_objects(std::vector<Body*> value){
    this->objects = value;
}

void RT_World::Start(){
    this->get_player()->Run(this->get_objects());
    for(int i = 0;i < this->get_objects().size();i++){
        this->get_objects()[i]->Run(this->get_objects());
    }
    
    this->check_event();
}

void RT_World::check_event(){
    this->check_event_hit();
}

void RT_World::check_event_hit(){
    std::vector<Area_Hit*> val = G_SINGLETON_action->get_action_hit();
    std::vector<Body*> obj = this->get_objects();

    for(int i = 0;i < val.size();i++){
        int32_t ml = val[i]->get_x() - (val[i]->get_w() / 2);
        int32_t mr = val[i]->get_x() + (val[i]->get_w() / 2);
        int32_t mt = val[i]->get_y() + (val[i]->get_h() / 2);
        int32_t mb = val[i]->get_y() - (val[i]->get_h() / 2);
    
        for(int j = 0;j < obj.size();j++){
            if(obj[i]->get_box_hit() != nullptr){
                int32_t tl = obj[i]->get_transform()->get_x() - (obj[i]->get_transform()->get_w() / 2);
                int32_t tr = obj[i]->get_transform()->get_x() + (obj[i]->get_transform()->get_w() / 2);
                int32_t tt = obj[i]->get_transform()->get_y() + (obj[i]->get_transform()->get_h() / 2);
                int32_t tb = obj[i]->get_transform()->get_y() - (obj[i]->get_transform()->get_h() / 2);
    
                if((mr >= tl && ml <= tr) || (ml <= tr && mr > tl)){ // do the sending hit
                    Transform* trs = obj[i]->get_transform();
                    Shader* shd = obj[i]->get_material()->get_shader();
                    Attribute* attr = obj[i]->get_attribute();
                    obj[i]->get_box_hit()->action(trs, shd, attr);
                }
            }
        }
    }

    G_SINGLETON_action->set_action_hit({});
}