class Solution {
public:
    vector<int> grayCode(int32_t pNumber) 
    {
        std::vector<int32_t> deduce(1 << pNumber);

        for (size_t i = 0; i < deduce.size(); ++i)
        {
            deduce[i] = (i xor (i >> 1));
        }

        return deduce;
    }
};
