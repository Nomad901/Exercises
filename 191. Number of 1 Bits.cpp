class Solution {
public:
    int32_t hammingWeight(int32_t n) 
    {
        std::bitset<32> numberInBin(n);
        std::string strInBin = numberInBin.to_string();
        return std::ranges::count(strInBin, '1');
    }
};
