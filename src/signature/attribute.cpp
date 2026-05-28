#include <signature/attribute.h>

Attribute::Attribute(int32_t health){
    this->set_health(health);
}

int32_t Attribute::get_health(){
    return this->health;
}

void Attribute::set_health(int32_t value){
    this->health = value;
}

uint8_t Attribute::get_amount(){
    return this->amount;
}

void Attribute::set_amount(uint8_t value){
    this->amount = value;
}

void Attribute::hit(int32_t* damage, Transform* transform, Shader* shader){
    int colorLoc = glGetUniformLocation(shader->get_ID(), "uColor");

    std::vector<float> col = color::find_rgba_color_by_name(color::RED);
    glUniform4f(colorLoc, col[0], col[1], col[2], col[3]);

    unsigned int offsetLoc = glGetUniformLocation(shader->get_ID(), "uOffset");
    glUniform2f(offsetLoc, transform->get_x(), transform->get_y());

    this->set_health(this->get_health() - *damage);
}

void Attribute::Execute(Transform* transform, Shader* shader){
}