#include <iostream>
#include <string>
#include <vector>

std::string rgb_to_hex(int r, int g, int b)
{
    std::unordered_map<int, std::string> mapa{ {10, "A"},{11,"B"},{12,"C"},{13,"D"},{14,"E"},{15,"F"} };
    std::vector<int> digits{ r,g,b };
    std::vector<std::string> ready;
    std::string tmp;

    auto lambda = [&](int number) -> std::string
        {
            auto result = mapa.find(number);
            if (result != mapa.end()) return result->second;
            else return std::to_string(number);
        };

    int reminder = 0;
    int number = 0;

    for (int i = 0; i < 3; i++)
    {
        number = digits[i];
        if (number < 0) tmp = "00";
        if (number > 255) tmp = "FF";
        for (size_t i = 0; tmp.size() != 2; i++)
        {
            reminder = number % 16;
            tmp += lambda(reminder);
            number /= 16;
        }
        std::reverse(tmp.begin(), tmp.end());
        ready.push_back(tmp);
        tmp.clear();
    }

    for (auto& i : ready)
    {
        tmp += i;
    }

    return tmp;
}



int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}