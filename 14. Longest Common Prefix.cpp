class Solution {
public:
std::string longestCommonPrefix(std::vector<std::string>& pStrings)
{
    	std::ranges::sort(pStrings, [](const std::string& pFirst, const std::string& pSecond) -> bool
		{
			return pSecond.size() > pFirst.size();
		});
	std::string prefix = pStrings[0];

	for (int32_t i = 1; i < pStrings.size(); ++i)
	{
		for (int32_t j = 0; j < pStrings[i].size(); ++j)
		{
			if (j < prefix.size() &&
				prefix[j] != pStrings[i][j])
			{
				prefix.erase(j);
				if (prefix.empty())
					return "";
				break;
			}
		}
	}

	return prefix;
}
};
