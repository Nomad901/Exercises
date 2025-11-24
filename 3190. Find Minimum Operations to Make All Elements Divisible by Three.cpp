class Solution {
public:
    bool isNumberDivisableByThree(int32_t pNumber)
    {
        return pNumber % 3 == 0;
    }

    bool allNumbersAreDivisableByThree(const std::vector<int32_t>& pNumbers)
    {
        for (auto& i : pNumbers)
        {
            if (!isNumberDivisableByThree(i))
                return false;
        }
        return true;
    }

    int32_t incrementNumber(int32_t pNumber)
    {
        return ++pNumber;
    }
    int32_t decrementNumber(int32_t pNumber)
    {
        return --pNumber;
    }

    int32_t minimumOperations(const std::vector<int32_t>& pNumbers)
    {
        uint32_t numberOfOperations = 0;

        uint32_t numberOperationsIncr = 0;
        uint32_t numberOperationsDecr = 0;

        uint32_t currentNumber = 0;

        for (size_t i = 0; i < pNumbers.size(); ++i)
        {
            if (isNumberDivisableByThree(pNumbers[i]))
                continue;

            currentNumber = pNumbers[i];
            while (!isNumberDivisableByThree(currentNumber))
            {
                currentNumber++;
                numberOperationsIncr++;
            }
            currentNumber = pNumbers[i];
            while (!isNumberDivisableByThree(currentNumber))
            {
                currentNumber--;
                numberOperationsDecr++;
            }

            numberOfOperations += numberOperationsIncr > numberOperationsDecr ? numberOperationsDecr :
                numberOperationsIncr;
            numberOperationsDecr = 0;
            numberOperationsIncr = 0;
        }

        return numberOfOperations;
    }
};
