class Solution {
public:
int32_t maxProfit(std::vector<int32_t>& pPrices)
{
	if (pPrices.size() < 2)
		return 0;

	int32_t currentProfit = 0, maxProfit = 0;

	for (size_t i = 1; i < pPrices.size(); ++i)
	{
		int32_t dailyProfit = pPrices[i] - pPrices[i - 1];

		currentProfit = std::max(dailyProfit, dailyProfit + currentProfit);
		maxProfit = std::max(currentProfit, maxProfit);
	}

	return maxProfit;
}
};
