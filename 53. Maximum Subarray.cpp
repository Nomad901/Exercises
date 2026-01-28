class Solution {
public:
int32_t maxSubArray(const std::vector<int32_t>& pNumbers)
{
	int32_t currentSum = pNumbers[0];
	int32_t maxSum = pNumbers[0];

	for (size_t i = 1; i < pNumbers.size(); ++i)
	{
		currentSum = std::max(pNumbers[i], currentSum + pNumbers[i]);
		maxSum = std::max(maxSum, currentSum);
	}
	return maxSum;
}

};
