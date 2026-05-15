#pragma once

#include <glad/glad.h>
#include <string>

extern const char* vertexShaderSrc;
extern const char* fragmentShaderSrc;

class Shader {
    public:
        Shader(const char* vertexSrc, const char* fragmentSrc);
        void use();

        unsigned int get_ID();

    private:
        unsigned int ID;
};