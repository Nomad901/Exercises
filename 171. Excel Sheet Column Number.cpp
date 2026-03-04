class Solution {
public:
    int titleToNumber(string columnTitle)
    {
        int32_t result = 0;
        int32_t exponent = columnTitle.size() - 1;
        for (auto& i : columnTitle)
        {
            result += (i - 'A' + 1) * std::pow(26, exponent);
            exponent--;
        }    
        return result;
    }
};
