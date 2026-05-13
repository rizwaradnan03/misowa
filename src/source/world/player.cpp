#include <source/world/player.h>
#include <namespace/input.h>
#include <iostream>

Player::Player(float* verticle, int32_t sz) : BODY_Dynamic(verticle, sz){
    this->set_verticle(verticle);
    this->verticle_count = sz;
    
    this->update_shape();
}

float* Player::get_verticle(){
    return this->verticle;
}

void Player::set_verticle(float* value){
    this->verticle = value;
}

unsigned int* Player::get_indices(){
    return this->indices;
}

void Player::set_indices(unsigned int* value){
    this->indices = value;
}

int32_t Player::get_verticle_count(){
    return this->verticle_count;
}

void Player::set_verticle_count(int32_t value){
    this->verticle_count = value;
}

int32_t Player::get_indices_count(){
    return this->indices_count;
}

void Player::set_indices_count(int32_t value){
    this->indices_count = value;
}

void Player::update_shape(){
    int32_t memb = (this->verticle_count / 4) * 3;
    
    unsigned int ind[memb];
    for(int i = 0;i < memb;i++){
        if(i < memb / 2){
            ind[i] = i;
        }else{
            unsigned int calc = i - 1;
            if(calc > memb / 2){
                calc = 0;
            }

            ind[i] = calc;
        }
    }

    this->indices_count = memb;

    this->set_indices(ind);

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, this->verticle_count * sizeof(float), this->get_verticle(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, memb * sizeof(unsigned int), this->get_indices(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Player::movement(){
    std::string* kb = input::continuous_pressed();
    std::cout << "KB SEK " << kb << std::endl;
    if(kb == nullptr){
        return;
    }

    float amt = 0.1;

    int32_t tg;
    bool p_or_m;

    if(*kb == "TOP" || *kb == "BOTTOM"){
        tg = 0;

        if(*kb == "TOP"){
            p_or_m = true;
        }else{
            p_or_m = false;
        }
    }else{
        tg = 1;

        if(*kb == "RIGHT"){
            p_or_m = true;
        }else{
            p_or_m = false;
        }
    }

    float* dp = this->get_verticle();
    for(int i = 0;i < this->verticle_count;i++){
        if(i < 2){
            if(i == tg){
                p_or_m == true ? dp[i] += amt : dp[i] -= amt;
            }
        }else{
            if(i % 2 == tg){
                p_or_m == true ? dp[i] += amt : dp[i] -= amt;
            }
        }
    }

    this->set_verticle(dp);
    this->update_shape();
}

void Player::Run(){
    this->movement();
    this->Display();
}

void Player::Display(){
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, this->indices_count, GL_UNSIGNED_INT, 0);
}