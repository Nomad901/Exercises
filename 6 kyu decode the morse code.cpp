#include <iostream>
#include<vector>

std::string decodeMorse(const std::string& str) {
    static std::unordered_map<std::string, char> map1 = {
    {".-", 'A'}, {"-...",'B' }, {"-.-.",'C'},
    {"-..",'D'}, {".",'E'}, {"..-.",'F'},
    {"--.",'G'}, {"....",'H'}, {"..",'I'},
    {".---",'J'}, {"-.-",'K'}, {".-..",'L'},
    {"--",'M'}, {"-.",'N'}, {"---",'O'},
    {".--.",'P'}, {"--.-",'Q'}, {".-.",'R'},
    {"...",'S'}, {"-",'T'}, {"..-",'U'},
    {"...-",'V'}, {".--",'W'}, {"-..-",'X'},
    {"-.--",'Y'}, {"--..", 'Z'}, {"-.-.--", '!'},
        {"..--..", '?'},{".-.-.-",'.'},{"--..--",','}
    };
    std::string tmp0 = "";
    std::string tmp2 = str;
    int counter = 0;

    if (str == " " || str.empty()) return str;
    if (str == "...---...") return "SOS";

    else {
        if (tmp2[0] == ' ') {
            for (int i = 0; i < tmp2.size(); ++i) {
                if (tmp2[0] == ' ' && !tmp2.empty()) tmp2.erase(0, 1);
                else break;
            }
        }
        if (tmp2[tmp2.size() - 1] == ' ') {
            for (int i = 0; i < tmp2.size(); ++i) {
                if (tmp2[tmp2.size() - 1] == ' ' && !tmp2.empty()) tmp2.erase(tmp2.size() - 1, tmp2.size());
                else break;
            }
        }

        std::stringstream ss(tmp2);
        std::string chank;
        while (ss >> chank) {
            if (chank == "...---...") {
                tmp0 += "SOS";
            }
            else {
                auto it = map1.find(chank);
                if (it == map1.end()) {
                    return "Error!";
                }
                tmp0.push_back(it->second);
            }
            counter = chank.size();
            tmp2.erase(0, std::min(size_t(counter), tmp2.size()));
            if (!tmp2.empty() && tmp2[0] == ' ' && tmp2.size() > 1 && tmp2[1] == ' ')
            {
                tmp0.push_back(' ');
                tmp2.erase(0, std::min(size_t(3), tmp2.size()));
            }
            else {
                tmp2.erase(0, std::min(size_t(1), tmp2.size()));
            }
        }
    }
    return tmp0;
}




int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}