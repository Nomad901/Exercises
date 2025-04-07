#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> solution(const std::string& s)
{
    std::vector<std::string> vctStr;
    std::string tmp;
    if (s.empty()) return {};
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0 && i != 0) {
            vctStr.push_back(tmp);
            if (vctStr[vctStr.size() - 1].size() == 1) { vctStr[vctStr.size() - 1].push_back('_'); }
            tmp.clear();
        }
        tmp.push_back(s[i]);
    }
    vctStr.push_back(tmp);
    if (vctStr[vctStr.size() - 1].size() == 1) { vctStr[vctStr.size() - 1].push_back('_'); }

    return vctStr;
}



int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}