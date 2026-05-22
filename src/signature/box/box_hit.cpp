#include <signature/box/box_hit.h>

void Box_hit::action(int32_t* damage, Transform* transform, Shader* shader, Attribute* attribute){
    attribute->hit(damage, transform, shader);
}