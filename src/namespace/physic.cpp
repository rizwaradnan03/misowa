#include <namespace/physic.h>

namespace physic
{
    std::pair<bool, std::string*> check_collide(Mesh *me, Mesh *target)
    {
        std::vector<float> vm = me->get_verticles();
        std::vector<float> vt = target->get_verticles();

        float m_l = vm[0];
        float m_b = vm[1];
        float m_r = vm[2];
        float m_t = vm[5];

        float t_l = vt[0];
        float t_b = vt[1];
        float t_r = vt[2];
        float t_t = vt[5];

        if (
            m_r <= t_l ||
            m_l >= t_r ||
            m_t <= t_b ||
            m_b >= t_t)
        {
            return {false, nullptr};
        }

        float left = abs(m_r - t_l);
        float right = abs(t_r - m_l);
        float top = abs(t_t - m_b);
        float bottom = abs(m_t - t_b);

        float min_overlap = std::min(
            std::min(left, right),
            std::min(top, bottom));

        std::string* direction = nullptr;

        if (min_overlap == left)
        {
            direction = new std::string("RIGHT");
        }
        else if (min_overlap == right)
        {
            direction = new std::string("LEFT");
        }
        else if (min_overlap == top)
        {
            direction = new std::string("BOTTOM");
        }
        else
        {
            direction = new std::string("TOP");
        }

        return {true, direction};
    }
};