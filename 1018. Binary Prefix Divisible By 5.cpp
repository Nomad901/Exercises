class Solution {
public:
    std::vector<bool> prefixesDivBy5(const std::vector<int32_t>& pNumbers)
    {
        std::vector<bool> numberOfTrue(pNumbers.size());
        uint32_t residueOfDividing = 0;
        for (size_t i = 0; i < numberOfTrue.size(); ++i)
        {
            uint32_t equation = residueOfDividing * 2 + pNumbers[i];
            residueOfDividing = equation % 5;

            if (residueOfDividing == 0)
                numberOfTrue[i] = true;
            else
                numberOfTrue[i] = false;
        }

        return numberOfTrue;
    }
};
