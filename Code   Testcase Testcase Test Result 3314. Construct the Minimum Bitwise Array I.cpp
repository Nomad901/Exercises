class Solution {
public:
std::vector<int32_t> minBitwiseArray(const std::vector<int32_t>& pNumbers)
{
	std::vector<int32_t> answer;
	answer.reserve(pNumbers.size());
	uint32_t currentIndexForCheck = 0;

	for (int32_t i = 0; answer.size() < pNumbers.size(); ++i)
	{
		if (currentIndexForCheck == pNumbers.size())
			break;

		int32_t number = i | (i + 1);
		if (number > pNumbers[currentIndexForCheck] * 2)
		{
			answer.push_back(-1);
			currentIndexForCheck++;
			i = 0;
		}
		else if (number == pNumbers[currentIndexForCheck])
		{
			answer.push_back(i);
			currentIndexForCheck++;
			i = 0;
		}
	}

	return answer;
}

};
