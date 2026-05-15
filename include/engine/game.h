#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <singleton/gl.h>
#include <engine/shader.h>
#include <nodes/body/body.h>
#include <render_type/world.h>
#include <render_type/gui.h>
#include <singleton/system.h>

class Game {
    public:
        void Init(GLFWwindow *win);
        void Start();
};