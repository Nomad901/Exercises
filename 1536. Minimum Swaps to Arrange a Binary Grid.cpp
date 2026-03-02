class Solution {
public:
static constexpr int32_t getMaxIndex(const std::vector<int32_t> pStorage)
{
	for (int32_t i = std::ssize(pStorage) - 1; i >= 0; --i)
	{
		if (pStorage[i] == 1)
			return i;
	}
	return -1;
}

int32_t minSwaps(std::vector<std::vector<int32_t>>& pGrid)
{
	int32_t size = pGrid.size();
	std::vector<int32_t> indicesOfRightmost;
	indicesOfRightmost.reserve(pGrid.empty() ? 0 : pGrid.size() * pGrid[0].size());

	for (auto& i : pGrid)
		indicesOfRightmost.push_back(getMaxIndex(i));
	
	int32_t result = 0;
	for (int32_t i = 0; i < size; ++i)
	{
		int32_t required = i;
		int32_t j = i;
		while (j < size && indicesOfRightmost[j] > required)
			j++;
		
		if (j == size)
			return -1;

		while (j > i)
		{
			std::swap(indicesOfRightmost[j], indicesOfRightmost[j - 1]);
			result++;
			j--;
		}
	}
	return result;
}

};
