class Solution {
public:
bool isDividableByThree(int32_t pNumber)
{
    return pNumber % 3 == 0;
}

std::vector<int32_t> getSubarray(const std::vector<int32_t>& pNumbers,
                                 const std::vector<size_t>& pIndexToMiss)
{
    std::vector<int32_t> subArray;
    subArray.reserve(pNumbers.size());

    auto hasIndex = [&pIndexToMiss](size_t pIndex) -> bool
        {
            auto it = std::find(pIndexToMiss.begin(), pIndexToMiss.end(), pIndex);

            return it != pIndexToMiss.end();
        };

    for (size_t i = 0; i < pNumbers.size(); ++i)
    {
        if (!hasIndex(i))
            subArray.push_back(pNumbers[i]);
    }
    return subArray;
}

uint32_t getSumOfArray(const std::vector<int32_t>& pArray)
{
    uint32_t number = 0;
    for (auto& i : pArray)
    {
        number += i;
    }
    return number;
}


int32_t maxSumDivThree(const std::vector<int32_t>& pNumbers)
{
    if (pNumbers.size() == 1)
    {
        if (isDividableByThree(pNumbers[0]))
            return true;
        return false;
    }

    std::vector<int32_t> numbersSum;
    numbersSum.reserve(pNumbers.size() * pNumbers.size());
    uint32_t currentIndex = 0;

    std::vector<size_t> indicesToMiss;
    indicesToMiss.reserve(2);
    indicesToMiss.push_back(0);

    while (numbersSum.size() < (pNumbers.size() * pNumbers.size()))
    {
        std::vector<int32_t> subArray = getSubarray(pNumbers, indicesToMiss);
        
        uint32_t sumOfSubArray = getSumOfArray(subArray);
        if(sumOfSubArray % 3 == 0)
           numbersSum.push_back(sumOfSubArray);

        if (indicesToMiss[currentIndex] == pNumbers.size())
        {
            if (indicesToMiss.size() == 1)
            {
                indicesToMiss[currentIndex] = 0;
                currentIndex++;
                indicesToMiss.push_back(0);
            }
            else
            {
                indicesToMiss[0]++;
                indicesToMiss[currentIndex] = 0;
            }
        }

        indicesToMiss[currentIndex]++;
    }

    auto maxSum = std::max_element(numbersSum.begin(), numbersSum.end());
    
    return *maxSum;
}
};
