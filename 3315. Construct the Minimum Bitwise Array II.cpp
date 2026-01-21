class Solution {
public:
std::vector<int32_t> minBitwiseArray(std::vector<int32_t>& pNumbers)
{
	for (auto& i : pNumbers)
	{
		int32_t result = -1;
		int32_t tmp = 1;
		while ((i & tmp) != 0)
		{
			result = i - tmp;
			tmp <<= 1;
		}
		i = result;
	}
	return pNumbers;
}
};
