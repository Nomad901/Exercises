class Solution {
public:
char nextGreatestLetter(std::vector<char>& pLetters, char pTarget)
{
	for (auto& i : pLetters)
	{
		int32_t target = pTarget - 'a';
		int32_t current = i - 'a';
		if (current > target)
			return i;
	}

	return pLetters[0];
}
};
