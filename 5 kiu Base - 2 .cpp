#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <memory>
#include <type_traits>
#include <algorithm>
#include <numeric>
#include <map>
#include <cctype>
#include <unordered_map>
#include <sstream>
#include <regex>
#include <array>
#include <unordered_set>
#include <set>
#include <ctime>
#include <fstream>
#include <sstream>
#include <utility>
#include <array>
#include <cmath>

class Negabinary {
public:
    static std::string ToNegabinary(int i);
    static int ToInt(std::string s);
};


std::string Negabinary::ToNegabinary(int i)
{
    std::cout << i << '\n';

    if (i == 0) return "0";

    std::string remainders;
    int remainder = 0;
    
    while (i != 0) {
        remainder = i % -2;
        i /= -2;

        if (remainder < 0) {
            remainder += 2;
            i += 1;
        }
        remainders += std::to_string(remainder);
    }

    std::reverse(remainders.begin(), remainders.end());
    
    return remainders;
}

int Negabinary::ToInt(std::string s)
{
    std::cout << s << '\n';

    if (s == "0") return 0;

    std::unordered_map<int, int>binary;
    std::vector<std::pair<int, int>> vctOfPair{ { 0, 1 }, {1,-2} };
    constexpr unsigned int max = std::numeric_limits<int>::max() / 2;

    int current_value = 0;
    for (int i = 2; ; i++)
    {
        current_value = std::abs(vctOfPair[i - 1].second) * 2;

        if (current_value >= max) break;

        if (i % 2 == 0) vctOfPair.push_back({ i,current_value });
        else vctOfPair.push_back({ i,-current_value });
    }
    for (auto& i : vctOfPair)
    {
        binary.emplace(i);
    }

    int counter = 0;
    std::reverse(s.begin(), s.end());

    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '1') {
            auto result = binary.find(i);
            if (result != binary.end()) {
                counter += result->second;
            }
        }
    }

    return counter;
}

int main()
{    
    Negabinary nb;
    std::cout<<nb.ToNegabinary(6)<<'\n';
    std::cout<<nb.ToInt("11001000010101")<<'\n';


    return 0;
}

