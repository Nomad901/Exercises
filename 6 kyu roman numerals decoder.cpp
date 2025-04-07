#include <iostream>
#include <string>

int solution(std::string roman) {
    std::unordered_map<char, int> map1 = {
        {'I', 1},{'V',5},{'X',10},{'L',50},
        {'C',100},{'D',500},{'M',1000}
    };
    int deduce = 0;
    int spare = 0;

    for (auto& i : roman)
    {
        auto it = map1.find(i);

        if (deduce != 0 && spare < it->second)
        {
            deduce += (it->second - spare) - spare;
        }
        else
        {
            deduce += it->second;
        }
        spare = it->second;
    }

    return deduce;
}




int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}