class Solution {
public:
int32_t lengthOfLastWord(std::string pString)
{
    	auto it = pString.find_last_not_of(' ');
	pString.erase(it + 1);
	if (pString.find(' ') == std::string::npos)
		return pString.size();

	for (size_t i = pString.size() - 1; i >= 1; --i)
	{
		if (pString[i] != ' ' &&
			pString[i - 1] == ' ')
		{
			return static_cast<int32_t>(pString.substr(i,
				pString.find_last_not_of(' ') - i + 1).size());
		}
	}
	return 1;
}
};
