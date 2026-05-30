#ifndef ENGINE_GAME_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <config/c_app.h>
#include <engine/shader.h>
#include <nodes/body/body.h>
#include <render_type/world.h>
#include <render_type/gui.h>
#include <singleton/g_system.h>
#include <singleton/g_gl.h>
#include <singleton/g_action.h>
#include <singleton/g_player.h>
#include <singleton/g_cache.h>

class Game {
    public:
        void Init(GLFWwindow *win);
        void Start();
};

#endif