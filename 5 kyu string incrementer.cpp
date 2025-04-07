#include <iostream>
#include<vector>

#include <string>

std::string incrementString(const std::string& str)
{
    if (str.empty()) return "1";
    std::string s = str;
    std::string tmp;
    bool b = 1;
    size_t j = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i])) {
            j = i;
            for (size_t r = i; r < s.size(); r++)
            {
                tmp.push_back(s[r]);
                if (!isdigit(tmp[tmp.size() - 1]))
                {
                    b = 0;
                    break;
                }
            }
            if (b) {
                s.erase(j);
                break;
            }
            tmp.clear();
            i++;
        }
        b = 1;
    }

    if (!tmp.empty()) {
        int l = stoi(tmp);
        l++;
        tmp = std::to_string(l);
        s += tmp;
        for (size_t i = 0; i < s.size() - 1;++i) {
            if (s.size() < str.size()) {
                tmp.insert(0, "0");
                s.push_back('s');
            }
            else
            {
                s.erase(j);
                s += tmp;
                return s;
            }
        }
    }
    else {
        s.push_back('1');
    }
    return s;
}



int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}