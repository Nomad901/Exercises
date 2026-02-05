class Solution {
public:
std::vector<int32_t> constructTransformedArray(const std::vector<int32_t>& pNumbers)
{
	std::vector<int32_t> result(pNumbers.size());

	for (size_t i = 0; i < pNumbers.size(); ++i)
	{
		int32_t steps = 0;
		int32_t index = i;
		if (pNumbers[i] > 0)
		{
			while (steps != pNumbers[i])
			{
				steps++;
				if (index != pNumbers.size() - 1)
					++index;
				else
					index = 0;
			}
			result[i] = pNumbers[index];
		}
		else if (pNumbers[i] < 0)
		{
			while (steps != std::abs(pNumbers[i]))
			{
				steps++;
				if (index != 0)
					--index;
				else
					index = pNumbers.size() - 1;
			}
			result[i] = pNumbers[index];
		}
		else
		{
			result[i] = pNumbers[i];
		}
	}
	
	return result;
}
};
