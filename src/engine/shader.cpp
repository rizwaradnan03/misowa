#include <engine/shader.h>

const char* vertexShaderSrc = R"(
#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTex;

out vec2 TexCoords;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 0.0, 1.0);
    TexCoords = aTex;
}
)";

const char* fragmentShaderSrc = R"(
#version 330 core
in vec2 TexCoords;
out vec4 FragColor;

uniform vec4 uColor;
uniform sampler2D tex;

void main()
{
    FragColor = uColor;
    // FragColor = texture(tex, TexCoords);
}
)";

static unsigned int compile(unsigned int type, const char* src)
{
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);
    return shader;
}

Shader::Shader(const char* vertexSrc, const char* fragmentSrc){
    unsigned int vs = compile(GL_VERTEX_SHADER, vertexSrc);
    unsigned int fs = compile(GL_FRAGMENT_SHADER, fragmentSrc);

    ID = glCreateProgram();
    glAttachShader(ID, vs);
    glAttachShader(ID, fs);
    glLinkProgram(ID);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

void Shader::use(){
    glUseProgram(ID);
}

unsigned int Shader::get_ID(){
    return this->ID;
}