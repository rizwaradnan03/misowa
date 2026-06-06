#include <nodes/body/body_dynamic.h>

BODY_Dynamic::BODY_Dynamic(Transform* transform, Mesh* mesh, Material* material, Trait* trait) : Body(transform, mesh, material, trait){
    Camera* iCam = new Camera(transform->get_x(), transform->get_y());
    Movement* iMovement = new Movement();

    this->set_id(identifier::generate_id("body_dynamic"));
    this->set_transform(transform);
    this->set_mesh(mesh);
    this->set_material(material);
    this->set_camera(iCam);
    this->set_movement(iMovement);
    this->set_trait(trait);
}

BODY_Dynamic::~BODY_Dynamic(){
    delete this->get_transform();
    delete this->get_mesh();
    delete this->get_material();
    delete this->get_trait();
    delete this->get_box_hit();
    delete this->get_movement();
    delete this->get_camera();
}

std::string BODY_Dynamic::get_id(){
    return this->id;
}

void BODY_Dynamic::set_id(std::string value){
    this->id = value;
}

Transform* BODY_Dynamic::get_transform(){
    return this->transform;
}

void BODY_Dynamic::set_transform(Transform* value){
    this->transform = value;
}

Mesh* BODY_Dynamic::get_mesh(){
    return this->mesh;
}

void BODY_Dynamic::set_mesh(Mesh* value){
    this->mesh = value;
}

Material* BODY_Dynamic::get_material(){
    return this->material;
}

void BODY_Dynamic::set_material(Material* value){
    this->material = value;
}

Trait* BODY_Dynamic::get_trait(){
    return this->trait;
}

void BODY_Dynamic::set_trait(Trait* value){
    this->trait = value;
}

Movement* BODY_Dynamic::get_movement(){
    return this->movement;
}

void BODY_Dynamic::set_movement(Movement* value){
    this->movement = value;
}

Camera* BODY_Dynamic::get_camera(){
    return this->camera;
}

void BODY_Dynamic::set_camera(Camera* value){
    this->camera = value;
}

void BODY_Dynamic::physic(const std::vector<Body*>& objects){
    this->object_collide(objects);
}

void BODY_Dynamic::object_collide(const std::vector<Body*>& objects){}

void BODY_Dynamic::camera_alligner(){}

void BODY_Dynamic::Execute(const std::vector<Body*>& objects){
    this->camera_alligner();
    this->physic(objects);    
    this->Display();
    this->get_movement()->Execute(this->get_transform(), this->get_mesh());
}

void BODY_Dynamic::Display(){
    this->get_material()->Execute(this->get_transform());
    this->get_mesh()->Execute(this->get_transform());
}