#ifndef GUI_GUI_ITEM_H
#define GUI_GUI_ITEM_H

#include <string>
#include <chrono>
#include <dto/dto_gui_item.h>
#include <nodes/gui/gui_click.h>
#include <source/scene/world/object/player.h>
#include <source/scene/world/gui/gui_inventory.h>

class Player;
class GUI_inventory;

class GUI_item: public GUI_click {
    public:
        GUI_item(Transform* transform, Mesh* mesh, Material* material, PoleSet poleSet, std::string* item, GuiItemType type, uint8_t amount);
        ~GUI_item();
        
        virtual Transform* get_transform() override;
        virtual void set_transform(Transform* value) override;

        virtual Mesh* get_mesh() override;
        virtual void set_mesh(Mesh* value) override;

        virtual Material* get_material() override;
        virtual void set_material(Material* value) override;
        
        virtual float get_pole_x() override;
        virtual void set_pole_x(float value) override;
        
        virtual float get_pole_y() override;
        virtual void set_pole_y(float value) override;

        std::string* get_item();
        void set_item(std::string* value);

        GuiItemType get_type();
        void set_type(GuiItemType value);

        uint8_t get_amount();
        void set_amount(uint8_t value);

        std::chrono::time_point<std::chrono::high_resolution_clock>* get_elapse_choose();
        void set_elapse_choose(std::chrono::time_point<std::chrono::high_resolution_clock>* value);

        virtual void hit_action();
        void reset_elapse_choose_checker();
        virtual void Execute(Transform* transform) override;

    private:
        Transform* transform;
        Mesh* mesh;
        Material* material;

        std::string* item;
        
        GuiItemType type;
        uint8_t amount;

        std::chrono::time_point<std::chrono::high_resolution_clock>* elapse_choose;

        float pole_x, pole_y;
};

#endif