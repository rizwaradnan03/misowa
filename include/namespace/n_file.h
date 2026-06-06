#ifndef NAMESPACE_FILE_H
#define NAMESPACE_FILE_H

#include <config/c_pch.h>

namespace file {
    std::vector<std::pair<std::string, std::variant<int, float, std::string>>> read_whole_file(std::string path);
    std::vector<std::pair<std::string, std::variant<int, float, std::string>>> find_value_with_exact_key(std::vector<std::pair<std::string, std::variant<int, float, std::string>>> arr, std::string search);
};

#endif