#pragma once

#include <glad/glad.h>
#include <string>

class shader {
    public:
        shader(const char* vertexSrc, const char* fragmentSrc);
        void use();

    private:
        unsigned int ID;
};