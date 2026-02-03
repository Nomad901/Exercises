class Solution {
public:
std::vector<int32_t> twoSum(std::vector<int32_t>& pNumbers, int32_t pTarget)
{
	for (size_t i = 0; i < pNumbers.size(); ++i)
	{
		for (size_t j = i + 1; j < pNumbers.size(); ++j)
		{
			if (pNumbers[i] + pNumbers[j] == pTarget)
				return { int32_t(i), int32_t(j) };
		}
	}
	return { 0, 0 };
}
};
