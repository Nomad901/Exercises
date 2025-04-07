#include <vector>

bool contains_all(const std::vector<int>& arr, const std::vector<int>& target) {

    bool tmp = 1;

    for (auto& i : target)
    {
        for (auto& j : arr) {
            if (i == j)
            {
                tmp = 1;
                break;
            }
            else tmp = 0;
        }
        if (tmp == 0) return tmp;
    }

    return tmp;
}




int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}