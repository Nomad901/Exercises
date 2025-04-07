#include <string>
#include <vector>
#include <algorithm>

std::string highestScoringWord(const std::string& str)
{
    std::string alphabet = { " abcdefghijklmnopqrstuvwxyz" };
    std::vector<std::string> vectorForStr;
    std::vector<int> positionOfAlphabet;
    std::string tmpForStr;
    int counterAlpha = 0;
    int deduce = 0;

    for (auto& i : str)
    {
        if (i != ' ') {
            tmpForStr.push_back(i);
        }
        else {
            vectorForStr.push_back(tmpForStr);
            tmpForStr.clear();
        }
    }
    vectorForStr.push_back(tmpForStr);

    for (auto& i : vectorForStr)
    {
        tmpForStr = i;
        for (int i = 0; i < tmpForStr.size(); ++i)
        {
            for (int j = 0; j < alphabet.size(); j++)
            {
                if (tmpForStr[i] == alphabet[j]) {
                    counterAlpha += j;
                    break;
                }
            }
        }
        positionOfAlphabet.push_back(counterAlpha);
        counterAlpha = 0;
    }

    auto it = std::max_element(positionOfAlphabet.begin(), positionOfAlphabet.end());

    for (int i = 0; i < positionOfAlphabet.size(); i++)
    {
        if (*it == positionOfAlphabet[i]) {
            deduce = i;
            break;
        }
    }

    tmpForStr.clear();
    tmpForStr = vectorForStr[deduce];

    return tmpForStr;
}

int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}