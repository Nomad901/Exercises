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
#include <utility>
#include <cmath>
#include <print>
#include <format>
#include <tuple>
#include <coroutine>

#include <vector>

int findNum(int n) {
    if (n < 10)
        return n;

    std::vector<int> sequence{ 0,1,2,3,4,5,6,7,8,9,10 };
    sequence.reserve(n);
    std::vector<int> indexes;
    indexes.reserve(3);
    std::vector<int> indexes2;
    indexes.reserve(3);


    auto breakigNumber = [&](int& number, std::vector<int>& vctr)
        {
            std::string breakNum2 = std::to_string(number);
            for (size_t i = 0; i < breakNum2.size(); i++)
            {
                std::string number = "";
                number.push_back(breakNum2[i]);
                vctr.emplace_back(stoi(number));
            }
        };

    for (int i = 10; sequence.size() - 1 != static_cast<size_t>(n); ++i)
    {
        breakigNumber(sequence[sequence.size() - 1], indexes);

        for (int i2 = 10; sequence.size() * 3; ++i2)
        {
            breakigNumber(i2, indexes2);
            if (std::invoke([&]()->bool
                {
                    bool tmp = false;
                    for (auto& i : indexes2)
                    {
                        auto it = std::find(indexes.begin(), indexes.end(), i);
                        auto it2 = std::find(sequence.begin(), sequence.end(), i2);
                        if (it == indexes.end() && it2 == sequence.end())
                            tmp = true;
                        else
                            return false;
                    }
                    return tmp;
                }))
            {
                sequence.push_back(i2);
                break;
            }
            indexes2.clear();
        }
        indexes.clear();
    }
    return sequence[n];
}

int main()
{


    return 0;
}
