#include <singleton/system.h>

System* G_SINGLETON_system = nullptr;

void System::change_screen(R_TYPE rt, std::string scr){
    if(rt == WORLD){
        RTW = new RT_World();
        RTW->Init(scr); // gotta change
    }else{

    }

    this->render_type = new R_TYPE(rt);
}

R_TYPE* System::get_render_type(){
    return this->render_type;
}

Shader* System::get_shader(){
    return this->shader;
}

void System::set_shader(Shader* value){
    this->shader = value;
}