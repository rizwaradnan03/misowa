#include <namespace/color.h>

namespace color {
    std::vector<std::pair<C_Type, std::vector<float>>> SYS_Color = {
        std::make_pair(GREEN, std::vector<float>{0.0, 1.0, 0.0, 1.0}),
        std::make_pair(RED, std::vector<float>{1.0, 0.0, 0.0, 1.0}),
        std::make_pair(BLUE, std::vector<float>{0.0, 0.0, 1.0, 1.0}),
        std::make_pair(WHITE, std::vector<float>{1.0, 1.0, 1.0, 1.0}),
    };
    
    std::vector<float> find_rgba_color_by_name(C_Type col){
        for(int i = 0;i < SYS_Color.size();i++){
            if(SYS_Color[i].first == col){
                return SYS_Color[i].second;
            }
        }

        return {};
    }
};