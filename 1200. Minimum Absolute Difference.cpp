class Solution {
public:
std::vector<std::vector<int32_t>> minimumAbsDifference(std::vector<int32_t>& pArray)
{
	std::multimap<int32_t, std::vector<int32_t>> differences;
	
	std::ranges::sort(pArray);

	for (size_t i = 0; i < pArray.size() - 1; ++i)
	{
		int32_t difference = pArray[i + 1] - pArray[i];
		std::vector<int32_t> vector = { pArray[i + 1],  pArray[i] };
		std::ranges::sort(vector);
		differences.emplace(difference, vector);
	}
	
	std::vector<std::vector<int32_t>> result;
	result.reserve(differences.size());
	int32_t targetKey = differences.begin()->first;
	for (auto& [key, value] : differences)
	{
		if (key != targetKey)
			break;
		result.push_back(value);
	}

	return result;
}

};
