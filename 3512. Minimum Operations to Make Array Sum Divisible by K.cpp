class Solution {
public:
int32_t minOperations(const std::vector<int32_t>& pNumbers, int32_t pNumber)
{
	int32_t sum = std::accumulate(pNumbers.begin(), pNumbers.end(), 0);
	int32_t secondSum = sum;
	int32_t result = sum;

	while (sum % pNumber != 0 && 
		   secondSum % pNumber != 0)
	{
		if (sum % pNumber != 0)
			sum--;
		else
			secondSum++;
	}

	sum = std::min(sum, secondSum);

	return result > sum ? result - sum : sum - result;
}
};
