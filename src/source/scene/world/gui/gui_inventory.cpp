#include <source/scene/world/gui/gui_inventory.h>
#include <source/scene/world/gui/gui_item.h>

GUI_inventory* G_GUI_inventory = nullptr;

GUI_inventory::GUI_inventory(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet): GUI_container(transform, mesh, material, poleSet){
    this->set_id(identifier::generate_id("gui_inventory"));
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_pole_x(poleSet.x);
    this->set_pole_y(poleSet.y);

    G_GUI_inventory = this;
}

GUI_inventory::~GUI_inventory(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();

    std::vector<std::pair<PARTICLE_item*, GUI_item*>> nd = this->get_nodes();

    for(int i = 0;i < nd.size();i++){
        delete nd[i].first;
        delete nd[i].second;
    }
}

std::string GUI_inventory::get_id(){
    return this->id;
}

void GUI_inventory::set_id(std::string value){
    this->id = value;
}

Transform* GUI_inventory::get_transform(){
    return this->transform;
}

void GUI_inventory::set_transform(Transform* value){
    this->transform = value;
}

Mesh* GUI_inventory::get_mesh(){
    return this->mesh;
}

void GUI_inventory::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* GUI_inventory::get_material(){
    return this->material;
}

void GUI_inventory::set_material(Material* value){
    this->material = value;
}

std::string* GUI_inventory::get_select_item(){
    return this->select_item;
}

void GUI_inventory::set_select_item(std::string* value){
    this->select_item = value;
}

float GUI_inventory::get_pole_x(){
    return this->pole_x;
}

void GUI_inventory::set_pole_x(float value){
    this->pole_x = value;
}

float GUI_inventory::get_pole_y(){
    return this->pole_y;
}

void GUI_inventory::set_pole_y(float value){
    this->pole_y = value;
}

std::vector<std::pair<PARTICLE_item*, GUI_item*>> GUI_inventory::get_nodes(){
    return this->nodes;
}

void GUI_inventory::set_nodes(std::vector<std::pair<PARTICLE_item*, GUI_item*>> value){
    this->nodes = value;
}

void GUI_inventory::Execute(Transform* transform){
    Transform* changeTrans = new Transform(transform->get_x() + this->get_pole_x(), transform->get_y() + this->get_pole_y(), this->get_transform()->get_w(), this->get_transform()->get_h());
    this->set_transform(changeTrans);
    
    this->get_material()->Execute(this->get_transform());
    this->get_mesh()->Execute(this->get_transform());

    std::pair<float, float> posWithPole = input::mouse_position_with_player_as_pole();

    for(int i = 0;i < this->get_nodes().size();i++){
        GUI_item* g = this->get_nodes()[i].second;
        g->Execute(this->get_transform());

        float wH = g->get_transform()->get_w() / 2;
        float hH = g->get_transform()->get_h() / 2;

        float left = g->get_transform()->get_x() - wH;
        float right = g->get_transform()->get_x() + wH;
        float top = g->get_transform()->get_y() - hH;
        float bottom = g->get_transform()->get_y() + hH;

        if(posWithPole.first >= left && posWithPole.first <= right && posWithPole.second >= top && posWithPole.second <= bottom){
            if(this->get_select_item() == nullptr){
                this->set_select_item(new std::string(g->get_id()));
            }else{
                if(*this->get_select_item() == g->get_id()){
                    Transform* hTrans = new Transform(*G_OBJECT_player->get_transform());
                    
                    float wHH = hTrans->get_w() / 2;
                    float hHH = hTrans->get_w() / 2;
                    
                    float vert[] = {
                        hTrans->get_x() - wHH, hTrans->get_y() - hHH,
                        hTrans->get_x() + wHH, hTrans->get_y() - hHH,
                        hTrans->get_x() + wHH, hTrans->get_y() + hHH,
                        hTrans->get_x() - wHH, hTrans->get_y() + hHH,
                    };

                    Mesh* hMesh = new Mesh(vert, 8);
                    Material* hMat = new Material(*this->get_nodes()[i].first->get_material());

                    PARTICLE_item* pItem = new PARTICLE_item(hTrans, hMesh, hMat);
                    if(G_OBJECT_player->get_holded_right() == nullptr){
                        pItem->get_transform()->set_x(pItem->get_transform()->get_x() + (G_OBJECT_player->get_transform()->get_x() * 0.25));
                        G_OBJECT_player->set_holded_right(pItem);
                    }else{
                        pItem->get_transform()->set_x(pItem->get_transform()->get_x() - (G_OBJECT_player->get_transform()->get_x() * 0.25));
                        G_OBJECT_player->set_holded_left(pItem);
                    }
                }else{
                    this->set_select_item(new std::string(g->get_id()));
                }
            }
        }
    }
}