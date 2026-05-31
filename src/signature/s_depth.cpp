#include <signature/st_depth.h>

Depth::Depth(){
    this->set_dive_time(nullptr);
    this->set_oxygen_level(5);
}

std::chrono::time_point<std::chrono::high_resolution_clock>* Depth::get_dive_time(){
    return this->dive_time;
}

void Depth::set_dive_time(std::chrono::time_point<std::chrono::high_resolution_clock>* value){
    this->dive_time = value;
}

int32_t Depth::get_oxygen_level(){
    return this->oxygen_level;
}

void Depth::set_oxygen_level(int32_t value){
    this->oxygen_level = value;
}

void Depth::calculate_long_dive(Attribute* attribute){
    std::chrono::time_point<std::chrono::high_resolution_clock>* time = this->get_dive_time();
    if(time == nullptr){
        return;
    }

    auto current_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> differ = current_time - *time;

    if((int32_t)differ.count() % 2 == 0){
        // hit using attribute im gonna do next time

        int32_t depthBarLevel = (int32_t)differ.count() / 2;
        int32_t barToDisplay = this->get_oxygen_level() - depthBarLevel;
    }
}

void Depth::check_collide_with_water(){
    if(true){ // do: gotta change please because we need
        if(this->get_dive_time() != nullptr){
            return;
        }

        std::chrono::time_point<std::chrono::high_resolution_clock>* current_time = new std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::high_resolution_clock::now());
        this->set_dive_time(current_time);
    }
}

void Depth::Execute(Attribute* attribute){ //if colliding with water so we can start em
    this->check_collide_with_water();
    this->calculate_long_dive(attribute);
}