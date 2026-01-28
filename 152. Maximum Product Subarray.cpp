class Solution {
public:
int32_t maxProduct(const std::vector<int32_t>& pNumbers)
{
	if (pNumbers.empty())
		return 0;

	int32_t minProduct = pNumbers[0];
	int32_t maxProduct = pNumbers[0];
	int32_t result = pNumbers[0];

	for (size_t i = 1; i < pNumbers.size(); ++i)
	{
		if (pNumbers[i] < 0)
			std::swap(minProduct, maxProduct);

		minProduct = std::min(pNumbers[i], minProduct * pNumbers[i]);
		maxProduct = std::max(pNumbers[i], maxProduct * pNumbers[i]);

		result = std::max(result, maxProduct);
	}

	return result;
}
};
