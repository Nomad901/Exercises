#include <iostream>
#include<vector>

std::size_t duplicateCount1(const std::string& in) {
    std::unordered_map<char, int> charCount;
    std::size_t duplicates = 0;

    std::string checker = in;
    std::transform(checker.begin(), checker.end(), checker.begin(), ::tolower);

    for (char ch : checker) {
        charCount[ch]++;
    }

    for (const auto& pair : charCount) {
        if (pair.second > 1) {
            duplicates++;
        }
    }

    return duplicates;
}



int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}