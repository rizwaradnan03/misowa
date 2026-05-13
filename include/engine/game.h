#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <singleton/gl.h>
#include <engine/shader.h>
#include <nodes/body/body.h>
#include <render_type/world.h>
#include <render_type/gui.h>

enum GameType {
    WORLD,
    GUI
};

class Game {
    public:
        void Init(GLFWwindow *win);
        void Start();

        enum GameType get_type();
        void set_type(enum GameType value);

    private:
        enum GameType type;
};