#ifndef DTO_BULLET_H
#define DTO_BULLET_H

struct Target {
    float x;
    float y;
};

enum BulletType {
    PISTOL,
    LASER,
    FIRE
};

struct BulletInterval {
    float x;
    float y;
};

#endif