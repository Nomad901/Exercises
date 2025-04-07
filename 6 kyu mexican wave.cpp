#include <iostream>
#include<vector>

std::vector<std::string> wave(std::string y) {
    if (y.size() != 0) {
        std::string temp = y;
        std::vector<std::string> vectstr;
        for (int i = 0; i < y.size(); i++)
        {
            if (temp[i] == ' ') { continue; }
            temp[i] = std::toupper(temp[i]);
            vectstr.push_back(temp);
            temp[i] = std::tolower(temp[i]);
        }
        return vectstr;
    }
    return {};
}


int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}