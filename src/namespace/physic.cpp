#include <namespace/physic.h>

namespace physic {
    std::pair<bool, std::string*> check_collide(Mesh* me, Mesh* target){
        std::string* direct = nullptr;
        bool is_collide = false;

        std::vector<float> vm = me->get_verticles();
        std::vector<float> vt = target->get_verticles();

        float m_b = vm[1];
        float m_t = vm[5];
        float m_r = vm[2];
        float m_l = vm[0];

        float t_b = vm[1];
        float t_t = vm[5];
        float t_r = vm[2];
        float t_l = vm[0];

        if(m_b <= t_b && m_b > t_t){
            is_collide = true;
            direct = new std::string("BOTTOM");
        }else if(m_t >= t_b && m_t < t_t){
            is_collide = true;
            direct = new std::string("TOP");
        }else if(m_r >= t_l && m_r < t_r){
            is_collide = true;
            direct = new std::string("RIGHT");
        }else if(m_l <= t_r && m_l > t_l){
            is_collide = true;
            direct = new std::string("LEFT");
        }

        return std::make_pair(is_collide, direct);
    }
};