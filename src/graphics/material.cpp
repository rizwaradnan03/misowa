#include <graphics/material.h>
#include <singleton/system.h>
#include <iostream>

Material::Material( float r, float g, float b, float a){
    this->set_shader(G_SINGLETON_system->get_shader());
    this->set_r(r);
    this->set_g(g);
    this->set_b(b);
    this->set_a(a);
}

Shader* Material::get_shader(){
    return this->shader;
}

void Material::set_shader(Shader* value){
    this->shader = value;
}

float Material::get_r(){
    return this->r;
}

void Material::set_r(float value){
    this->r = value;
}

float Material::get_g(){
    return this->g;
}

void Material::set_g(float value){
    this->g = value;
}

float Material::get_b(){
    return this->b;
}

void Material::set_b(float value){
    this->b = value;
}

float Material::get_a(){
    return this->a;
}

void Material::set_a(float value){
    this->a = value;
}

void Material::Execute(int32_t x, int32_t y){
    this->get_shader()->use();

    unsigned int colorLoc = glGetUniformLocation(this->get_shader()->get_ID(), "uColor");

    glUniform4f(
        colorLoc,
        this->get_r(),
        this->get_g(),
        this->get_b(),
        this->get_a()
    );

    unsigned int offsetLoc = glGetUniformLocation(this->get_shader()->get_ID(), "uOffset");

    glUniform2f(offsetLoc, (float)x, (float)y);
}