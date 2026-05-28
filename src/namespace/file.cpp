#include <namespace/file.h>

namespace file {
    std::vector<std::pair<std::string, std::variant<int, float, std::string>>> read_whole_file(std::string path){
        std::vector<std::pair<std::string, std::variant<int, float, std::string>>> ans;
    
        std::string stfPath = "storage/file/" + path;
        std::ifstream file(stfPath);
        
        if(file.is_open() == false){
            return {};
        }
        
        std::stringstream buffer;
        buffer << file.rdbuf();
        
        for(int i = 0;i < buffer.str().size();i++){
            if(buffer.str()[i] == '\"'){
                std::string key = "";
                std::string value = "";

                bool key_mode = true;
                for(int j = i + 1;j < buffer.str().size();j++){
                    if(buffer.str()[j] != '\"'){
                        if(key_mode == true){
                            key +=  buffer.str()[j];
                        }else{
                            value +=  buffer.str()[j];
                        }
                    }else{
                        if(key_mode == true){
                            key_mode = false;
                        }else{
                            i = j + 1;
                            break;
                        }

                        if(j + 1 >= buffer.str().size()){
                            break;
                        }

                        for(int k = j + 1;k < buffer.str().size();k++){
                            if(buffer.str()[k] == '\"'){
                                j = k;
                                break;
                            }
                        }
                    }
                }

                try{
                    std::string* stats;
                    for(int j = 0;j < value.size();j++){
                        if(value[j] == '0'){
                            int numberized = value[j - 1] - '0';
                            if(numberized >= 0 && numberized <= 9){
                                stats = new std::string("FLOAT");
                            }
                        }
                    }

                    if(stats == nullptr){
                        if(std::stoi(value)){
                            stats = new std::string("INT");
                        }
                    }

                    if(stats != nullptr){
                        if(*stats == "FLOAT"){
                            ans.push_back(std::make_pair(key, std::stof(value)));
                        }else{
                            ans.push_back(std::make_pair(key, std::stoi(value)));
                        }
                    }

                }catch(...){
                    ans.push_back(std::make_pair(key, value)); // failed then is a string
                }
            }
        }

        return ans;
    }
};