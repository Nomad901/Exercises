class Solution {
public:
bool isTrionic(std::vector<int32_t>& pNumbers)
{
	int32_t numberOfIncreasing = 0, numberOfDecreasing = 0;
	int32_t previousNumberOfIncreasing = 0, previousNumberOfDecreasing = 0;
	for (size_t i = 0; i < pNumbers.size() - 1; ++i)
	{
		if (pNumbers[i + 1] > pNumbers[i])
		{
			if(previousNumberOfIncreasing == numberOfIncreasing)
				numberOfIncreasing++;
			previousNumberOfDecreasing = numberOfDecreasing;
		}
		else if (pNumbers[i + 1] < pNumbers[i])
		{
			if (previousNumberOfDecreasing == numberOfDecreasing)
				numberOfDecreasing++;
			previousNumberOfIncreasing = numberOfIncreasing;
		}
		else 
			return false;
	}

	return numberOfIncreasing == 2 && numberOfDecreasing == 1 ? true : false;
}

};
