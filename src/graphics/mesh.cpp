#include <graphics/mesh.h>

Mesh::Mesh(float vertex[], int32_t vertexSize){
    int32_t c_idn = (vertexSize / 4) * 3;
    this->indicesCount = c_idn;

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
    for(int i = 0;i < vertexSize;i++){
        vert.push_back(vertex[i]);
    }

    this->set_indices(ind);

    this->update_buffer();
    this->update_vao();
    this->set_verticles(vert);
    this->update_ebo();
    
    glVertexAttribPointer(
        0,
        2,
        GL_FLOAT,
        GL_FALSE,
        2 * sizeof(float),
        (void*)0
    );

    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

void Mesh::update_buffer(){
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);
}

void Mesh::update_vao(){
    glBindVertexArray(this->VAO);
}

void Mesh::update_vbo(){
    float vert[this->get_verticles().size()];
    for(int i = 0;i < this->get_verticles().size();i++){
        vert[i] = this->get_verticles()[i];
    }

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, this->get_verticles().size() * sizeof(float), vert, GL_STATIC_DRAW);
}

void Mesh::update_ebo(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indicesCount * sizeof(unsigned int), this->get_indices(), GL_STATIC_DRAW);
}

std::vector<float> Mesh::get_verticles(){
    return this->verticles;
}

void Mesh::set_verticles(std::vector<float> value){
    this->verticles = value;
    this->update_vbo(); // trigger update the vbo
}

unsigned int* Mesh::get_indices(){
    return this->indices;
}

void Mesh::set_indices(unsigned int* value){
    this->indices = value;
}

void Mesh::Execute(){
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, this->indicesCount, GL_UNSIGNED_INT, 0);
}