#include <namespace/n_file.h>

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
        
        std::string strizedBuf = buffer.str();
        uint16_t sz = strizedBuf.size();

        std::string parentKey = "";
        for(int i = 0;i < sz;i++){
            if(strizedBuf[i] == '\"'){
                uint16_t cp;
                for(int j = i + 1;j < sz;j++){
                    if(strizedBuf[j] == '\"'){
                        cp = j;
                        break;
                    }

                    parentKey += strizedBuf[j];
                }

                if(strizedBuf[cp + 3] == '\"'){
                    cp = cp + 3;
                    std::string val = "";

                    for(int j = cp + 1;j < sz;j++){
                        if(strizedBuf[j] == '\"'){
                            i = j;
                            break;
                        }

                        val += strizedBuf[j];
                    }

                    ans.push_back(std::make_pair(parentKey, val));
                    parentKey = "";
                }else if(strizedBuf[cp + 3] == '['){
                    for(int j = cp + 1;j < sz;j++){
                        if(strizedBuf[j] == ']'){
                            i = j;
                            break;
                        }else{
                            if(strizedBuf[j] == '\"'){
                                std::string key = "";
                                std::string val = "";
                                uint8_t spaced = 0;

                                for(int k = j + 1;k < sz;k++){
                                    if(strizedBuf[k] != '\"'){
                                        if(strizedBuf[k] == ':'){
                                            k++;
                                        }else{
                                            if(spaced == 0){
                                                key += strizedBuf[k];
                                            }else{
                                                val += strizedBuf[k];
                                            }
                                        }

                                    }else if(strizedBuf[k] == '\"'){
                                        spaced++;
                                        if(spaced == 3){
                                            j = k + 1;
                                            break;
                                        }
                                    }
                                }

                                int ct = 1;
                                std::string combined = parentKey + "_" + key;

                                for(int i = 0;i < ans.size();i++){
                                    for(int j = 0;j < combined.size();j++){
                                        if(combined[j] != ans[i].first[j]){
                                            break;
                                        }

                                        if(j == combined.size() - 1){
                                            ct++;
                                        }
                                    }
                                }

                                combined += "_" + (char)ct;

                                ans.push_back(std::make_pair(combined, val));
                            }
                        }
                    }

                    parentKey = "";
                }
            }
        }

        std::ofstream log_file("storage/log/player.txt");

        for(int i = 0;i < ans.size();i++){
            std::string cvtVal = std::get<std::string>(ans[i].second);

            try{
                bool is_num = true;
                for(int j = 0;j < cvtVal.size();j++){
                    if(cvtVal[j] == '.'){
                        int bef = cvtVal[j - 1] - '0';
                        if(bef >= 0 && bef <= 9){
                            is_num = false;
                            break;
                        }
                    }
                }

                if(is_num == true){
                    int cvt = std::stoi(cvtVal);
                    ans[i].second = cvt;
                }else{
                    float cvt = std::stof(cvtVal);
                    ans[i].second = cvt;
                }

            }catch(...){
                log_file << "Gagal Konversi : " << cvtVal;
            }
        }

        log_file.close();

        return ans;
    }
    std::vector<std::pair<std::string, std::variant<int, float, std::string>>> find_value_with_exact_key(std::vector<std::pair<std::string, std::variant<int, float, std::string>>> arr, std::string search){
        std::vector<std::pair<std::string, std::variant<int, float, std::string>>> toRet;

        for(int i = 0;i < arr.size();i++){
            bool isDo = false;

            for(int j = 0;j < arr[i].first.size();j++){
                if(arr[i].first[j] == search[0]){
                    int dg = j;

                    for(int k = 0;k < search.size();k++){
                        if(search[k] != arr[i].first[dg + k]){
                            j = k;
                            break;
                        }

                        if(k == search.size() - 1){
                            isDo = true;
                            toRet.push_back(arr[i]);
                            break;
                        }
                    }

                    if(isDo == true){
                        break;
                    }
                }
            }
        }

        return toRet;
    }
};