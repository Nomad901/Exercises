#include <array>
#include <string>

std::array<std::string, 2> oneTwoThree(const unsigned int n) {
    std::string firstNum;
    std::string secondNum;
    int counter = 0;
    if (n == 0) return { "0","0" };
    for (size_t i = 0; i < n; i++) {
        if (i == 9)
        {
            firstNum += std::to_string(i);
            i = 0;
        }
        if (secondNum.size() != n) {
            secondNum.push_back('1');
            counter = i + 1;
        }
        else  break;
    }
    firstNum += std::to_string(counter);
    if (n % 9 == 0) {
        firstNum.clear();
        for (size_t i = 0; i < n / 9; i++) { firstNum.push_back('9'); }
    }
    return { firstNum, secondNum };
}




int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}