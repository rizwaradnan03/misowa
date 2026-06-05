#ifndef GRAPHIC_MESH_H
#define GRAPHIC_MESH_H

#include <config/c_pch.h>
#include <namespace/n_color.h>
#include <graphics/g_transform.h>

class Mesh {
    public:
        Mesh(float vertex[], int32_t vertexSize);
    
        void update_buffer();
        void update_vao();
        void update_vbo();
        void update_ebo();

        std::vector<float> get_verticles();
        void set_verticles(std::vector<float> value);

        unsigned int* get_indices();
        void set_indices(unsigned int* value);

        void update(Transform* transform);
        void Execute(Transform* transform);

    private:
        std::vector<float> verticles;
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;

        unsigned int* indices;

        int32_t indicesCount;
};

#endif