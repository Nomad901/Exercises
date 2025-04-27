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

class ToSmallest
{
public:
  static std::vector<long long> smallest(long long n);
};

std::vector<long long> ToSmallest::smallest(long long n)
{
  std::string str = std::to_string(n);
  std::vector<std::vector<long long>> vec = { { n, 0, 0 } };
  for (int i = 0; i < str.length(); i++ )
  {
    for (int j = 0; j < str.length(); j++)
    {
      std::string tmpStr = str;
      tmpStr.erase(i, 1);
      tmpStr.insert(j, 1, str[i]);
      vec.push_back({ std::stoll(tmpStr), i, j});
    }
  }
  return *(std::min_element(vec.begin(), vec.end()));
}

int main()
{


    return 0;
}
