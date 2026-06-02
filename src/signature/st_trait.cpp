#include <signature/st_trait.h>

std::vector<TraitType> Trait::get_list(){
    return this->list;
}

void Trait::set_list(std::vector<TraitType> value){
    this->list = value;
}

void Trait::set_push_list(TraitType value){
    this->list.push_back(value);
}

bool Trait::find_exist(TraitType value){
    std::vector<TraitType> val = this->get_list();

    for(int i = 0;i < val.size();i++){
        if(val[i] == value){
            return true;
        }
    }

    return false;
}