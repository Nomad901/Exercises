class Solution {
public:
int32_t single(std::string_view pString)
{
	if (pString.empty())
		return 0;
	int32_t counter = 1, result = 1;
	for (size_t i = 1; i < pString.size(); ++i)
	{
		counter = pString[i] == pString[i - 1] ? counter + 1 : 1;
		result = std::max(result, counter);
	}
	return result;
}
int32_t duo(std::string_view pString, char pFirst, char pSecond)
{
	std::unordered_map<int32_t, int32_t> differences;
	differences[0] = -1;
	int32_t result = 0;
	int32_t delta = 0;
	for (size_t i = 0; i < pString.size(); ++i)
	{
		if (pString[i] != pFirst && pString[i] != pSecond)
		{
			differences.clear();
			differences[0] = i;
			delta = 0;
			continue;
		}

		delta += pString[i] == pFirst ? +1 : -1;

		if (differences.contains(delta))
			result = std::max(result, static_cast<int32_t>(i - differences[delta]));
		else
			differences[delta] = i;
	}
	return result;
}

int32_t trio(std::string_view pString)
{
	std::vector<int32_t> counter(3, 0);

	std::map<std::vector<int32_t>, int32_t> differences;
	differences[{0, 0}] = -1;

	int32_t result = 0;

	for (size_t i = 0; i < pString.size(); ++i)
	{
		counter[pString[i] - 'a']++;

		std::vector<int32_t> key = { counter[1] - counter[0], counter[2] - counter[0] };
		
		if (differences.contains(key))
			result = std::max(result, static_cast<int32_t>(i - differences[key]));
		else
			differences[key] = i;
	}

	return result;
}

int32_t longestBalanced(std::string_view pString)
{
	return std::max({ single(pString),
					  duo(pString, 'a', 'b'),
					  duo(pString, 'b', 'c'),
					  duo(pString, 'a', 'c'),
					  trio(pString) });
}
};
