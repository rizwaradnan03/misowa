#pragma once

#include <glad/glad.h>
#include <string>

class Shader {
    public:
        Shader(const char* vertexSrc, const char* fragmentSrc);
        void use();

    private:
        unsigned int ID;
};