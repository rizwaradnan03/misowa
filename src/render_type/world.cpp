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

    std::vector<GUI_container*> gContainers;
    Transform* ct1Trans = new Transform(0.0f, 0.0f, 210.0f, 60.0f);

    float wHalfct1 = ct1Trans->get_w() / 2;
    float hHalfct1 = ct1Trans->get_h() / 2;

    float vertCt1[8] = {
        ct1Trans->get_x() - wHalfct1, ct1Trans->get_y() - hHalfct1,
        ct1Trans->get_x() + wHalfct1, ct1Trans->get_y() - hHalfct1,
        ct1Trans->get_x() + wHalfct1, ct1Trans->get_y() + hHalfct1,
        ct1Trans->get_x() - wHalfct1, ct1Trans->get_y() + hHalfct1,
    };
    Mesh* ct1Mesh = new Mesh(vertCt1, 8);
    
    std::vector<float> ct1Col = color::find_rgba_color_by_name(color::WHITE);
    Material* ct1Mat = new Material(ct1Col[0], ct1Col[1], ct1Col[2], ct1Col[3]);

    PoleSet ps1;
    ps1.x = 0;
    ps1.y = -270;

    GUI_container* ct1 = new GUI_inventory(ct1Trans, ct1Mesh, ct1Mat, ps1);

    gContainers.push_back(ct1);

    p->set_gui_containers(gContainers);
    
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

void RT_World::Start(){
    std::vector<Body*> obj = this->get_objects();

    this->get_player()->Run(obj);

    for(int i = 0;i < obj.size();i++){
        Entity* enty;
        
        if(i < obj.size()){
            enty = obj[i];
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

    for(int i = 0;i < val.size();i++){
        double ml = val[i]->get_x() - (val[i]->get_w() / 2);
        double mr = val[i]->get_x() + (val[i]->get_w() / 2);
        double mt = val[i]->get_y() + (val[i]->get_h() / 2);
        double mb = val[i]->get_y() - (val[i]->get_h() / 2);
    
        for(int j = 0;j < obj.size();j++){
            Entity* enty;

            if(j < obj.size()){
                enty = obj[j];
            }

            if(enty->get_box_hit() != nullptr){
                float tl = enty->get_transform()->get_x() - (enty->get_transform()->get_w() / 2);
                float tr = enty->get_transform()->get_x() + (enty->get_transform()->get_w() / 2);
                float tt = enty->get_transform()->get_y() + (enty->get_transform()->get_h() / 2);
                float tb = enty->get_transform()->get_y() - (enty->get_transform()->get_h() / 2);
    
                if((mr >= tl && ml <= tr) || (ml <= tr && mr > tl)){
                    if(j < obj.size()){ // hitted
                        Transform* trs = enty->get_transform();
                        Shader* shd = enty->get_material()->get_shader();
                        Attribute* attr = enty->get_attribute();
                        enty->get_box_hit()->action(val[i]->get_damage(), trs, shd, attr);
                    }
                }
            }
        }
    }

    G_SINGLETON_action->set_action_hit({});
}