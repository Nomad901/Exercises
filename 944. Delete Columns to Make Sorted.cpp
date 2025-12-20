class Solution {
public:
std::vector<std::string> getStringsInColumnSpace(const std::vector<std::string>& pStrings)
{
	std::vector<std::string> stringsInColumnSpace;
	stringsInColumnSpace.reserve(pStrings.size());

	uint32_t index = 0;
	std::string singleColumnString;

	for (size_t i = 0; i < pStrings.size(); ++i)
	{
		singleColumnString.push_back(pStrings[i][index]);

		if (i + 1 == pStrings.size())
		{
			index++;
			i = -1;
			stringsInColumnSpace.push_back(singleColumnString);
			singleColumnString.clear();
		}
		if (index >= pStrings[0].size())
			break;
	}

	return stringsInColumnSpace;
}

int32_t minDeletionSize(const std::vector<std::string>& pStrings)
{
	std::vector<std::string> columnStrings = getStringsInColumnSpace(pStrings);

	int32_t numberUnsortedStrings = 0;
	for (auto& i : columnStrings)
	{
		std::string reversedString = i;
		std::reverse(reversedString.begin(), reversedString.end());

		if (!std::ranges::is_sorted(i) &&
			!(i.size() == 1))
		{
			numberUnsortedStrings++;
		}
	}
	return numberUnsortedStrings;
}
};
