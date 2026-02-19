class Solution {
public:
int32_t countBinarySubstrings(std::string pString)
{
	std::vector<int32_t> storage;
	storage.reserve(pString.size());

	while (pString.size())
	{
		auto index = pString.find_first_not_of(pString[0]);
		if (index != std::string::npos)
		{
			storage.push_back(index);
			pString.erase(0, index);
		}
		else
		{
			storage.push_back(pString.size()); 
			break;
		}
	}

	int32_t sum = 0;
	for (size_t i = 0; i < storage.size() - 1; ++i)
	{
		sum += std::min(storage[i], storage[i + 1]);
	}

	return sum;
}
};
