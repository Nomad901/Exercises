class Solution {
public:
    int findFinalValue(vector<int>& pNumbers, int pOriginal)
    {
        auto iterator = std::find(pNumbers.begin(), pNumbers.end(), pOriginal);
        if (iterator == pNumbers.end())
            return pOriginal;
        
        int32_t returnNumber = pOriginal;
        for (size_t i = 0; i < pNumbers.size(); ++i)
        {
            returnNumber *= 2;
            auto iterator = std::find(pNumbers.begin(), pNumbers.end(), returnNumber);
            if (iterator == pNumbers.end())
                return returnNumber;
        }

        return returnNumber;    
    }
};
