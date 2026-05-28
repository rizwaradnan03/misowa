#pragma once

#include <vector>
#include <string>

enum TraitType {
    BREAKABLE,
    BOUNCE,
    ANCHOR,
};

class Trait {
    public:
        std::vector<TraitType> get_list();
        void set_list(std::vector<TraitType> value);
        void set_push_list(TraitType value);
        bool find_exist(TraitType value);

    private:
        std::vector<TraitType> list;
};