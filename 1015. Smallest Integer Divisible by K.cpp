class Solution {
public:
    int32_t smallestRepunitDivByK(int32_t pNumber)
    {
        if (pNumber % 2 == 0 &&
            pNumber % 5 == 0)
        {
            return -1;
        }

        uint32_t reminder = 0;
        for (size_t i = 0; i < pNumber + 1; ++i)
        {
            reminder = (reminder * 10 + 1) % pNumber;
            if (reminder == 0)
                return i + 1;
        }

        return -1;
    }
};
