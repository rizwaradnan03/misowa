#include <signature/st_collide_mask.h>

CollideMask::CollideMask(std::vector<uint8_t> mask){
    this->set_mask(mask);
}

std::vector<uint8_t> CollideMask::get_mask(){
    return this->mask;
}

void CollideMask::set_mask(std::vector<uint8_t> value){
    this->mask = value;
}