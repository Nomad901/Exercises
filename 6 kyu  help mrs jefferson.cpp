#include <vector>
std::vector<int> shortestArrang(const int& n) {
    std::vector<int> vct;
    int number = 0;
    int tmp = 1;

    for (int i = n / 2 + 1; i > 0; )
    {
        number += i;
        vct.push_back(i);
        if (number == n) return vct;
        if (i == 1 || number > n)
        {
            i = n / 2 - tmp;
            tmp++;
            number = 0;
            vct.clear();
            continue;
        }
        --i;
    }
    return { -1 };
}


int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}