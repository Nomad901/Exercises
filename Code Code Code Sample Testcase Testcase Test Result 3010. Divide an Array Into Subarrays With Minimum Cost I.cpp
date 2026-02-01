class Solution {
public:
int32_t minimumCost(std::vector<int32_t>& pNumbers)
{
		int32_t sizeOfNumbers = pNumbers.size();
	int32_t minSum = INT_MAX;

	for (size_t i = 0; i <= sizeOfNumbers - 3; ++i)
	{
		for (size_t j = i + 1; j <= sizeOfNumbers - 2; ++j)
		{
			int32_t sum = pNumbers[0] + pNumbers[i + 1] + pNumbers[j + 1];
			minSum = std::min(minSum, sum);
		}
	}

	return minSum;
}
};
