#ifndef SINGLETON_CACHE_H

#include <vector>
#include <utility>
#include <string>
#include <namespace/file.h>

class SINGLETON_cache {
    public:
        SINGLETON_cache();    

        std::vector<std::pair<std::string, std::vector<std::pair<std::string, std::variant<int, float, std::string>>>>> get_statistic_file_readers();   
        std::vector<std::pair<std::string, std::variant<int, float, std::string>>> get_statistic_file_reader_by_name(std::string name);   
        void set_statistic_file_readers(std::vector<std::pair<std::string, std::vector<std::pair<std::string, std::variant<int, float, std::string>>>>> value);   
        void set_push_statistic_file_readers(std::pair<std::string, std::vector<std::pair<std::string, std::variant<int, float, std::string>>>> value);   

    private:
        std::vector<std::pair<std::string, std::vector<std::pair<std::string, std::variant<int, float, std::string>>>>> statistic_file_readers;
};

extern SINGLETON_cache* G_SINGLETON_cache;

#endif