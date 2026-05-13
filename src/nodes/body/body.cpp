#include <nodes/body/body.h>

Body::Body(float* verticle, int32_t sz){
    this->set_verticle(verticle);
    this->verticle_count = sz;
    
    this->update_shape();
}

float* Body::get_verticle(){
    return this->verticle;
}

void Body::set_verticle(float* value){
    this->verticle = value;
}

unsigned int* Body::get_indices(){
    return this->indices;
}

void Body::set_indices(unsigned int* value){
    this->indices = value;
}

int32_t Body::get_verticle_count(){
    return this->verticle_count;
}

void Body::set_verticle_count(int32_t value){
    this->verticle_count = value;
}

int32_t Body::get_indices_count(){
    return this->indices_count;
}

void Body::set_indices_count(int32_t value){
    this->indices_count = value;
}

void Body::update_shape(){
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

void Body::Run(){
    this->Display();
}

void Body::Display(){
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, this->indices_count, GL_UNSIGNED_INT, 0);
}