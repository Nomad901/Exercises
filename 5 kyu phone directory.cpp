#include <iostream>
#include <string>
#include <sstream>

class PhoneDir
{
public:
    static std::string phone(const std::string& orgdr, std::string num) {
        std::cout << num << '\n';

        std::string str = orgdr;
        std::string name;
        std::string phone;
        std::string adress;
        std::string unwanted{ "/;,#@^" };

        auto result = str.find(num);
        if (result > str.size()) {
            return "Error => Not found: " + num;
        }

        int number1 = 0;
        std::string mpt = str;
        auto result3 = mpt.find(num);
        while (result3 < mpt.size()) {
            number1++;
            mpt.erase(result3, 1);
            result3 = mpt.find(num);
            if (number1 == 2) return "Error => Too many people: " + num;
        }


        int number = 0;
        std::string chunk;
        std::stringstream ss(str);
        while (ss >> chunk) {
            if (!chunk.empty()) {
                if (chunk[0] != num[0]) chunk.erase(0, 1);
                else if (chunk[chunk.size() - 1] != num[num.size() - 1]) if (!chunk.empty())chunk.erase(chunk.size() - 1, chunk.size());
            }
        }

        if (result < str.size()) {
            bool temp = 1;
            for (size_t i = result; ; )
            {
                if (temp) {
                    if (str[i] == '\n' || i == 0) {
                        str.erase(0, i + 1);
                        temp = 0;
                        i = 0;
                    }
                    else i--;
                }
                else {
                    if (str[i] == '\n' || i == str.size() - 1) {
                        str.erase(i);
                        break;
                    }
                    else i++;
                }
            }
            std::string chunk2;
            std::stringstream ss2(str);
            while (std::getline(ss2, chunk2, ' '))
            {
                auto result = chunk2.find(">");
                if (result > chunk2.size()) result = chunk2.find("<");
                auto result1 = chunk2.find("+");
                if (result < chunk2.size()) {
                    name += chunk2;
                    name.push_back(' ');
                    continue;
                }
                else if (result1 < chunk2.size()) {
                    phone += chunk2;
                    continue;
                }
                else {
                    adress += chunk2;
                    adress.push_back(' ');
                }
            }
            adress.pop_back();
            if (adress[0] == ' ') { adress.erase(0, 1); }
            auto result1 = adress.find("_");
            if (result1 < adress.size())
            {
                adress.erase(result1, 1);
                if (adress[result1] != adress[0])
                    adress.insert(result1, " ");
            }
            name.pop_back();
            name.erase(0, 1);
            name.erase(name.size() - 1);
            auto result = name.find("_");
            if (result < name.size()) name.erase(result, result + 1);
            while (phone[0] != num[0]) phone.erase(0, 1);
            while (phone[phone.size() - 1] != num[num.size() - 1]) phone.erase(phone.size() - 1);
            for (size_t i = 0; i < name.size(); i++) { if (name[i] == ' ' && name[i + 1] == ' ') name.erase(i, 1); }
            for (size_t i = 0; i < adress.size(); i++) { if (adress[i] == ' ' && adress[i + 1] == ' ') adress.erase(i, 1); }
            for (size_t i = 0; i < phone.size(); i++) { if (phone[i] == ' ' && phone[i + 1] == ' ') phone.erase(i, 1); }
            adress.erase(std::remove_if(adress.begin(), adress.end(), [&](char c) {
                return unwanted.find(c) != std::string::npos;
                }), adress.end());
        }
        else {
            return "Error => Not found: " + num;
        }

        return "Phone => " + phone + ", Name => " + name + ", Address => " + adress;
    }
};




int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}