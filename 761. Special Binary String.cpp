class Solution {
public:
std::string makeLargestSpecial(std::string pString)
{
	int32_t count = 0;
	int32_t start = 0;

	std::vector<std::string> strings;

	for (int32_t i = 0; i < pString.size(); ++i)
	{
		count += (pString[i] == '1') ? +1 : -1;

		if (count == 0)
		{
			strings.push_back('1' + makeLargestSpecial(pString.substr(start + 1, i - start - 1)) + '0');
			start = i + 1;
		}
	}

	std::ranges::sort(strings, std::greater<std::string>());

	std::string result;
	for (auto& i : strings)
	{
		result += i;
	}

	return result;
}
};
