#include <singleton/g_player.h>

SINGLETON_player* G_SINGLETON_player = nullptr;

std::string* SINGLETON_player::get_select_item(){
    return this->select_item;
}

void SINGLETON_player::set_select_item(std::string* value){
    this->select_item = value;
}