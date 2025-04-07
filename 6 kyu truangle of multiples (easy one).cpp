#include <array>
#include <vector>

std::array<unsigned long, 3> multTriangle(const unsigned int n) {
    std::vector<int> vct;
    bool b = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = i + 1; j != i; )
        {
            if (j == i + 1)
                j = i;
            if (b == 1) {
                if ([&]()->bool {
                    int r = j / i;
                    if (r == i)
                        return true;
                    else
                        return false;
                    }())
                {
                    vct.push_back(j);
                    b = 0;
                }
                else {
                    vct.push_back(j);
                    j += i;
                }
            }
            else {
                if (j == i)
                {
                    b = 1;
                    break;
                }
                j -= i;
                vct.push_back(j);
            }
        }
        b = 1;
    }

    unsigned long total_sum = 0;
    unsigned long total_even_sum = 0;
    unsigned long total_odd_sum = 0;

    for (auto& i : vct)
    {
        total_sum += i;
        if (i % 2 == 0)
            total_even_sum += i;
        else
            total_odd_sum += i;
    }

    return { total_sum, total_even_sum, total_odd_sum };
}
}



int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}