#include <signature/box/hit.h>

void Box_hit::action(Transform* transform, Shader* shader, Attribute* attribute){
    attribute->hit(transform, shader);
}