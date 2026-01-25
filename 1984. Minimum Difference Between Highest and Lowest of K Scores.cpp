class Solution {
public:
int32_t minimumDifference(std::vector<int32_t>& pNumbers, int32_t pK)
{
	if (pK == 1)
		return 0;

	std::ranges::sort(pNumbers);

	std::vector<int32_t> sums;
	sums.reserve(pNumbers.size() * pK);

	for (size_t i = 0; i < pNumbers.size(); ++i)
	{
		std::vector<int32_t> storage = { pNumbers[i] };
		storage.reserve(pK);
		for (size_t j = i + 1; j < pNumbers.size(); ++j)
		{
			storage.push_back(pNumbers[j]);
			if (storage.size() >= pK)
			{
				std::ranges::sort(storage);
				int32_t result = storage.back() - storage.front();
				sums.push_back(result);
				storage = { pNumbers[i] };
			}
		}
	}
	std::ranges::sort(sums);

	return sums.front();
}
};
