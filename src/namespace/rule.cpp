#include <namespace/rule.h>

namespace rule {
    namespace equalize {
        int32_t divider = 2;

        float float_val(float value){
            return value / divider;
        }

        int32_t int_val(int32_t value){
            return value / divider;
        }
    };
};