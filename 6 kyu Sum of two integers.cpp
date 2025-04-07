#include <vector>
#include <string>
#include <random>
#include <memory>
#include <type_traits>
#include <algorithm>
#include <numeric>


int Add(int x, int y)
{
    std::vector<int> storage;
    storage.push_back(x); storage.push_back(y);
    int sum = std::accumulate(storage.begin(), storage.end(), 0);
    std::cout << sum;
    return sum;
}



int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}