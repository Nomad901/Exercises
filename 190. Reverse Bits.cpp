class Solution {
public:
    static int32_t reverseBits(int32_t& pNumber)
    {
        std::bitset<32> bits(pNumber);
        std::string bitsString = bits.to_string();
        std::ranges::reverse(bitsString);
        int32_t result = std::stoi(bitsString, nullptr, 2);
        return result;
    }
};
