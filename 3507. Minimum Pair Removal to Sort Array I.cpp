class Solution {
public:
int32_t minimumPairRemoval(std::vector<int32_t>& pNumbers)
{
	uint32_t numberOfOperations = 0;

	while (!std::ranges::is_sorted(pNumbers))
	{
		std::pair<int32_t, size_t> numberAndIndex = std::make_pair(std::numeric_limits<int32_t>::max(), 0);
		for (size_t i = 0; i < pNumbers.size() - 1; ++i)
		{
			int32_t sum = pNumbers[i] + pNumbers[i + 1];
			if (sum < numberAndIndex.first)
				numberAndIndex = std::make_pair(sum, i);
		}
		pNumbers[numberAndIndex.second] = numberAndIndex.first;
		auto it = pNumbers.begin();
		pNumbers.erase((it + numberAndIndex.second + 1 ));
		numberOfOperations++;
	}

	return numberOfOperations;
}
};
