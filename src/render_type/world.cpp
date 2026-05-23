#include <render_type/world.h>
#include <iostream>
#include <singleton/g_action.h>

RT_World* RTW = nullptr;

void RT_World::Init(std::string type){
    std::vector<Body*> obj_to_push;
    
    if(type == "MAIN"){
        float x_val = 120;
        float y_val = 120;

        while(y_val < 240){
            while(x_val < 300){
                Transform* bTrans = new Transform(x_val, y_val, 30.0f, 30.0f);
                float wHalf = bTrans->get_w() / 2;
                float hHalf = bTrans->get_h() / 2;

                float vert[8] = {
                    bTrans->get_x() - wHalf, bTrans->get_y() - hHalf,
                    bTrans->get_x() + wHalf, bTrans->get_y() - hHalf,
                    bTrans->get_x() + wHalf, bTrans->get_y() + hHalf,
                    bTrans->get_x() - wHalf, bTrans->get_y() + hHalf,
                };
                Mesh* bMesh = new Mesh(vert, 8);

                std::vector<float> col = color::find_rgba_color_by_name(color::GREEN);
                Material* bMat = new Material(col[0], col[1], col[2], col[3]);
                
                BODY_Static* st = new BODY_Static(bTrans, bMesh, bMat);
                obj_to_push.push_back(st);

                x_val += 30;
            }

            x_val = 120;
            y_val += 30;
        }
    }
    
    this->set_objects(obj_to_push);
    
    Transform* pTrans = new Transform(120.0f, 480.0f, 30.0f, 30.0f);
    float wHalf = pTrans->get_w() / 2;
    float hHalf = pTrans->get_h() / 2;

    float vert[8] = {
        pTrans->get_x() - wHalf, pTrans->get_y() - hHalf,
        pTrans->get_x() + wHalf, pTrans->get_y() - hHalf,
        pTrans->get_x() + wHalf, pTrans->get_y() + hHalf,
        pTrans->get_x() - wHalf, pTrans->get_y() + hHalf,
    };
    Mesh* pMesh = new Mesh(vert, 8);

    std::vector<float> col = color::find_rgba_color_by_name(color::RED);
    Material* pMat = new Material(col[0], col[1], col[2], col[3]);

    Player* p = new Player(pTrans, pMesh, pMat);
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

void RT_World::set_push_object(Body* value){
    this->objects.push_back(value);
}

std::vector<Gui*> RT_World::get_guis(){
    return this->guis;
}

void RT_World::set_guis(std::vector<Gui*> value){
    this->guis = value;
}

void RT_World::set_push_gui(Gui* value){
    this->guis.push_back(value);
}

void RT_World::Start(){
    std::vector<Body*> obj = this->get_objects();
    std::vector<Gui*> gui = this->get_guis();

    this->get_player()->Run(obj);

    for(int i = 0;i < obj.size() + gui.size();i++){
        Entity* enty;
        
        if(i < obj.size()){
            enty = obj[i];
        }else{
            enty = gui[i - obj.size()];
        }

        enty->Execute(obj);
    }

    this->check_event();
}

void RT_World::check_event(){
    this->check_event_hit();
}

void RT_World::check_event_hit(){
    std::vector<Area_Hit*> val = G_SINGLETON_action->get_action_hit();
    std::vector<Body*> obj = this->get_objects();
    std::vector<Gui*> gui = this->get_guis();

    for(int i = 0;i < val.size();i++){
        double ml = val[i]->get_x() - (val[i]->get_w() / 2);
        double mr = val[i]->get_x() + (val[i]->get_w() / 2);
        double mt = val[i]->get_y() + (val[i]->get_h() / 2);
        double mb = val[i]->get_y() - (val[i]->get_h() / 2);
    
        for(int j = 0;j < obj.size() + gui.size();j++){
            if(obj[i]->get_box_hit() != nullptr){
                float tl = obj[i]->get_transform()->get_x() - (obj[i]->get_transform()->get_w() / 2);
                float tr = obj[i]->get_transform()->get_x() + (obj[i]->get_transform()->get_w() / 2);
                float tt = obj[i]->get_transform()->get_y() + (obj[i]->get_transform()->get_h() / 2);
                float tb = obj[i]->get_transform()->get_y() - (obj[i]->get_transform()->get_h() / 2);
    
                if((mr >= tl && ml <= tr) || (ml <= tr && mr > tl)){
                    Transform* trs = obj[i]->get_transform();
                    Shader* shd = obj[i]->get_material()->get_shader();
                    Attribute* attr = obj[i]->get_attribute();
                    obj[i]->get_box_hit()->action(val[i]->get_damage(), trs, shd, attr);
                }
            }
        }
    }

    G_SINGLETON_action->set_action_hit({});
}