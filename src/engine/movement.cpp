#include <engine/movement.h>
#include <namespace/input.h>

Movement::Movement(){
    this->set_jump_stock(1);
    this->set_elapse_jump(nullptr);
}

int32_t Movement::get_jump_stock(){
    return this->jump_stock;
}

void Movement::set_jump_stock(int32_t value){
    this->jump_stock = value;
}

std::chrono::time_point<std::chrono::high_resolution_clock>* Movement::get_elapse_jump(){
    return this->elapse_jump;
}

void Movement::set_elapse_jump(std::chrono::time_point<std::chrono::high_resolution_clock>* value){
    this->elapse_jump = value;
}

void Movement::count_elapse_jump_time(Transform* transform, Mesh* mesh){
    if(this->get_elapse_jump() == nullptr){
        return;
    }

    auto current_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> differ = current_time - *this->get_elapse_jump();
    if(differ.count() < 2.0f){
        transform->set_y(transform->get_y() + dft::calc_displacement());
    }else{
        this->set_jump_stock(1);
        this->set_elapse_jump(nullptr);
    }

    this->trigger_change_position(transform, mesh);
}

void Movement::move(Transform* transform, Mesh* mesh, std::vector<bool> inavail){
    std::string* mov = input::continuous_pressed();
    if(mov == nullptr){
        return;
    }   

    if(*mov == "TOP"){
        if(this->get_jump_stock() > 0){
            std::chrono::time_point<std::chrono::high_resolution_clock>* current_time = new std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::high_resolution_clock::now());
            this->set_elapse_jump(current_time);

            this->set_jump_stock(this->get_jump_stock() - 1);
        }
    }else{
        float prevVal = transform->get_x();
        float calc = dft::calc_displacement();

        if(*mov == "LEFT"){
            calc *= -1;
        }

        transform->set_x(prevVal + calc);
    }

    this->trigger_change_position(transform, mesh);
}

void Movement::trigger_change_position(Transform* transform, Mesh* mesh){
    float xVal = transform->get_x();
    float yVal = transform->get_y();

    float wH = transform->get_w() / 2;
    float hH = transform->get_h() / 2;

    std::vector<float> crMesh = {
        xVal - wH, yVal - hH,
        xVal + wH, yVal - hH,
        xVal + wH, yVal + hH,
        xVal - wH, yVal + hH,
    };

    mesh->set_verticles(crMesh);
}

void Movement::Execute(Transform* transform, Mesh* mesh){
    this->count_elapse_jump_time(transform, mesh);
}