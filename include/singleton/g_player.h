#ifndef SINGLETON_PLAYER_H
#define SINGLETON_PLAYER_H

#include <string>

class SINGLETON_player {
    public:
        std::string* get_select_item();
        void set_select_item(std::string* value);

    private:
        std::string* select_item;
};

extern SINGLETON_player* G_SINGLETON_player;

#endif