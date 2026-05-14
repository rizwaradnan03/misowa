#include <nodes/body/dynamic.h>

BODY_Dynamic::BODY_Dynamic(float* verticle, int32_t sz) : Body(verticle, sz){
    this->verticle_count = sz;
    
    int32_t c_idn = (this->verticle_count / 4) * 3;
    
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

    this->indices_count = c_idn;
    
    this->set_verticle(vert);
    this->set_indices(ind);

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

std::vector<float> BODY_Dynamic::get_verticle(){
    return this->verticle;
}

void BODY_Dynamic::set_verticle(std::vector<float> value){
    this->verticle = value;
}

unsigned int* BODY_Dynamic::get_indices(){
    return this->indices;
}

void BODY_Dynamic::set_indices(unsigned int* value){
    this->indices = value;
}

int32_t BODY_Dynamic::get_verticle_count(){
    return this->verticle_count;
}

void BODY_Dynamic::set_verticle_count(int32_t value){
    this->verticle_count = value;
}

int32_t BODY_Dynamic::get_indices_count(){
    return this->indices_count;
}

void BODY_Dynamic::set_indices_count(int32_t value){
    this->indices_count = value;
}

void BODY_Dynamic::update_vbo(){
    float vx[this->verticle_count];
    for(int i = 0;i < this->verticle_count;i++){
        vx[i] = this->verticle[i];
    }

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, this->verticle_count * sizeof(float), vx, GL_STATIC_DRAW);
}

void BODY_Dynamic::movement(){}

void BODY_Dynamic::Run(){
    this->movement();
    this->Display();
}

void BODY_Dynamic::Display(){
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, this->indices_count, GL_UNSIGNED_INT, 0);
}