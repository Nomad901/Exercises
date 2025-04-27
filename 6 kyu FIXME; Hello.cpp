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

class Dinglemouse
{
public:

    Dinglemouse()
    {
        history.reserve(3);
    }

    Dinglemouse& setAge(int age)
    {
        auto it = history.find("age");

        if (it != history.end())
            sequence[it->second] = std::make_pair(". I am ", std::to_string(age));
        else
        {
            sequence[index] = std::make_pair(". I am ", std::to_string(age));
            history.emplace(std::make_pair("age", index));
            index++;
        }


        return *this;
    }

    Dinglemouse& setSex(const char sex)
    {
        auto it = history.find("sex");
        std::string tmp = std::invoke([&]()->std::string
            {
                if (sex == 'M')
                    return "male";
                else
                    return "female";
            });

        if (it != history.end())
            sequence[it->second] = std::make_pair(". I am ", tmp);
        else
        {
            sequence[index] = std::make_pair(". I am ", tmp);
            history.emplace(std::make_pair("sex", index));
            index++;
        }
        return *this;
    }

    Dinglemouse& setName(const std::string& name)
    {
        auto it = history.find("name");
        if (it != history.end())
            sequence[it->second] = std::make_pair(". My name is ", name);
        else
        {
            sequence[index] = std::make_pair(". My name is ", name);
            history.emplace(std::make_pair("name", index));
            index++;
        }
        return *this;
    }

    std::string hello()
    {
        std::string deduce = "Hello";
        for (auto& i : sequence)
        {
            deduce += i.first + i.second;
        }
        return deduce + ".";
    }
private:
    std::array<std::pair<std::string, std::string>, 3> sequence;
    std::unordered_map<std::string, int> history;
    int index{ 0 };
};

int main()
{


    return 0;
}
