#pragma once

#include <chrono>
#include <cstdint>
#include <vector>
#include <graphics/transform.h>
#include <namespace/default.h>
#include <graphics/mesh.h>
#include <graphics/transform.h>

class Movement {
    public: 
        Movement();
    
        int32_t get_jump_stock();
        void set_jump_stock(int32_t value);
        
        std::chrono::time_point<std::chrono::high_resolution_clock>* get_elapse_jump();
        void set_elapse_jump(std::chrono::time_point<std::chrono::high_resolution_clock>* value);
        
        void move(Transform* transform, Mesh* mesh, std::vector<bool> inavail);
        void Execute(Transform* transform, Mesh* mesh);
        void count_elapse_jump_time(Transform* transform, Mesh* mesh);
        void trigger_change_position(Transform* transform, Mesh* mesh);

    private:
        int32_t jump_stock;
        std::chrono::time_point<std::chrono::high_resolution_clock>* elapse_jump;
};