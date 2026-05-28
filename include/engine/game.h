#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <singleton/g_gl.h>
#include <engine/shader.h>
#include <nodes/body/body.h>
#include <render_type/world.h>
#include <render_type/gui.h>
#include <singleton/g_system.h>
#include <singleton/g_action.h>
#include <singleton/g_player.h>
#include <config/c_app.h>

class Game {
    public:
        void Init(GLFWwindow *win);
        void Start();
};