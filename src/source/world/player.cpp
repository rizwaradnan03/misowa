#include <source/world/player.h>
#include <iostream>

Player::Player(float verticle[], int32_t sz) : BODY_Dynamic(verticle, sz){
    this->set_verticle_count(sz);
    
    int32_t c_idn = (this->get_verticle_count() / 4) * 3;
    
    unsigned int ind[c_idn];
    for(int i = 0;i < c_idn;i++){
        if(i < c_idn / 2){
            ind[i] = i;
        }else{
            unsigned int calc = i - 1;
            if(calc > c_idn / 2){
                calc = 0;
            }

            ind[i] = calc;
        }
    }

    std::vector<float> vert;
    for(int i = 0;i < sz;i++){
        vert.push_back(verticle[i]);
    }

    this->set_indices_count (c_idn);
    
    this->set_verticle(vert);
    this->set_indices(ind);

    
    this->set_renderer(color::WHITE);

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);

    glBindVertexArray(VAO);

    this->update_vbo();

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, c_idn * sizeof(unsigned int), this->get_indices(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

std::vector<float> Player::get_verticle(){
    return this->verticle;
}

void Player::set_verticle(std::vector<float> value){
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

Shader* Player::get_shader(){
    return this->shader;
}

void Player::set_shader(Shader* value){
    this->shader = value;
}

void Player::update_vbo(){
    float vx[this->verticle_count];
    for(int i = 0;i < this->verticle_count;i++){
        vx[i] = this->verticle[i];
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, this->get_verticle_count() * sizeof(float), vx, GL_STATIC_DRAW);
}

void Player::set_renderer(color::C_Type color){
    std::vector<float> selected_col = color::find_rgba_color_by_name(color);

    char chng[1000];
    float r = selected_col[0];
    float g = selected_col[1];
    float b = selected_col[2];
    float a = selected_col[3];

    sprintf(
        chng,
        R"(
            #version 330 core
            out vec4 FragColor;

            void main()
            {
                FragColor = vec4(%f, %f, %f, %f);
            }
        )", r, g, b, a
    );

    
    const char* fragmented = chng; 
    
    Shader* shd = new Shader(vertexShaderSrc, fragmented);
    this->shader = shd;
}

void Player::movement(){
    std::string* kb = input::continuous_pressed();
    if(kb == nullptr){
        return;
    }

    int32_t tg = 0;
    bool p_or_m = false;

    if(*kb == "TOP" || *kb == "BOTTOM"){
        tg = 1;

        if(*kb == "TOP"){
            p_or_m = true;
        }else{
            p_or_m = false;
        }
    }else{
        tg = 0;

        if(*kb == "RIGHT"){
            p_or_m = true;
        }else{
            p_or_m = false;
        }
    }

    std::vector<float> vertex = this->get_verticle();
    for(int i = 0;i < this->get_verticle_count();i++){
        if(i < 2){
            if(tg == i){
                p_or_m ? vertex[i] += 0.0002f * dft::PLAYER_speed : vertex[i] -= 0.0002f * dft::PLAYER_speed;
            }
        }else{
            if(tg == (i % 2)){
                p_or_m ? vertex[i] += 0.0002f * dft::PLAYER_speed : vertex[i] -= 0.0002f * dft::PLAYER_speed;
            }
        }
    }

    this->set_verticle(vertex);
    this->update_vbo();
}

void Player::Run(){
    this->movement();

    this->shader->use();
    this->Display();
}

void Player::Display(){
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, this->indices_count, GL_UNSIGNED_INT, 0);
}