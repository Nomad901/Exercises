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

class PrimeDecomp
{
public:
    static std::string factors(int lst);
};

std::string PrimeDecomp::factors(int lst)
{
    std::string forDeduce;
    bool is_prime = false;
    for (int i = 2; i * i <= lst; i++)
    {
        if (lst % i == 0) { is_prime = false; break; }
        else is_prime = true;
    }
    if (is_prime) return "(" + std::to_string(lst) + ")";
    else {
        int tmpLst = lst;
        static int counter = 0;
        for (int i = 2; ; )
        {
            if (tmpLst % i == 0) {
                tmpLst /= i;
                counter++;
            }
            else {
                if (counter == 1)
                    forDeduce += "(" + std::to_string(i) + ")";
                else if (counter != 0)
                    forDeduce += "(" + std::to_string(i) + "**" + std::to_string(counter) + ")";
                i++;
                counter = 0;
                if (tmpLst <= 1)
                    break;
            }
        }
    }

    return forDeduce;

}

int main()
{


    return 0;
}
