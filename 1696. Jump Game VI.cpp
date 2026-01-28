class Solution {
public:
  int32_t maxResult(std::vector<int32_t>& pNumbers, int32_t pK)
{
	int32_t size = pNumbers.size();
	if (size == 0)
		return 0;

	std::vector<int32_t> dp(size, INT_MAX);
	dp[0] = pNumbers[0];

	std::priority_queue<std::pair<int32_t, int32_t>> maxHeap;
	maxHeap.push({ dp[0], 0 });

	for (int32_t i = 1; i < size; ++i)
	{
		while (!maxHeap.empty() && maxHeap.top().second < i - pK)
			maxHeap.pop();

		dp[i] = pNumbers[i] + maxHeap.top().first;
		maxHeap.push({ dp[i], i });
	}
	return dp[size - 1];
}
};
