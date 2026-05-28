#pragma once

#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#include <variant>

namespace file {
    std::vector<std::pair<std::string, std::variant<int, float, std::string>>> read_whole_file(std::string path);
};