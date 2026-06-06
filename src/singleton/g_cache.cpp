#include <singleton/g_cache.h>

SINGLETON_cache* G_SINGLETON_cache = nullptr;

SINGLETON_cache::SINGLETON_cache(){
    uint8_t az = 1;
    std::vector<std::pair<std::string, std::string>> files = {
        std::make_pair("player", "player.json"),
        std::make_pair("inventory", "inventory.json")
    };

    std::vector<std::pair<std::string, std::vector<std::pair<std::string, std::variant<int, float, std::string>>>>> toPush;
    for(int i = 0;i < az;i++){
        std::vector<std::pair<std::string, std::variant<int, float, std::string>>> data = file::read_whole_file(files[i].second);
        toPush.push_back(std::make_pair(files[i].first, data));
    }

    this->set_statistic_file_readers(toPush);
}

std::vector<std::pair<std::string, std::vector<std::pair<std::string, std::variant<int, float, std::string>>>>> SINGLETON_cache::get_statistic_file_readers(){
    return this->statistic_file_readers;
}

std::vector<std::pair<std::string, std::variant<int, float, std::string>>> SINGLETON_cache::get_statistic_file_reader_by_name(std::string name){
    for(int i = 0;i < this->get_statistic_file_readers().size();i++){
        if(this->get_statistic_file_readers()[i].first == name){
            return this->get_statistic_file_readers()[i].second;
        }
    }

    return {};
}

void SINGLETON_cache::set_statistic_file_readers(std::vector<std::pair<std::string, std::vector<std::pair<std::string, std::variant<int, float, std::string>>>>> value){
    this->statistic_file_readers = value;
}

void SINGLETON_cache::set_push_statistic_file_readers(std::pair<std::string, std::vector<std::pair<std::string, std::variant<int, float, std::string>>>> value){
    this->statistic_file_readers.push_back(value);
}