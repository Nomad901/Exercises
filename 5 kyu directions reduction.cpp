#include <iostream>
#include<vector>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(const std::vector<std::string>& arr);
    static const std::unordered_map<std::string, std::string> oppositeWays;
};

const std::unordered_map<std::string, std::string> DirReduction::oppositeWays{
    {"EAST", "WEST"},
    {"WEST", "EAST"},
    {"NORTH", "SOUTH"},
    {"SOUTH", "NORTH"},
};


std::vector<std::string> DirReduction::dirReduc(const std::vector<std::string>& arr) {
    std::vector<std::string> result;
    for (const auto& way : arr) {
        if (result.empty() || result.back() != oppositeWays.at(way)) {
            result.push_back(way);
        }
        else {
            result.pop_back();
        }
    }
    return result;
}

int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}