class Solution {
public:
int32_t longestBalanced(std::vector<int32_t>& pNumbers)
{
	int32_t size = pNumbers.size();
	int32_t result = 0;

	for (size_t i = 0; i < size; ++i)
	{
		std::unordered_set<int32_t> evenSet, oddSet;

		for (size_t j = i; j < size; ++j)
		{
			if (pNumbers[j] % 2 == 0)
				evenSet.emplace(pNumbers[j]);
			else
				oddSet.emplace(pNumbers[j]);

			if (evenSet.size() == oddSet.size())
				result = std::max(result, static_cast<int32_t>(j - i + 1));

			if (result >= size - i)
				break;
		}
		if (result >= size - i)
			break;
	}

	return result;
}
};
