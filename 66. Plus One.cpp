class Solution {
public:
std::vector<int32_t> plusOne(const std::vector<int32_t>& pDigits)
{
	std::vector<int32_t> result = pDigits;

	for (int32_t i = result.size() - 1; i >= 0; --i)
	{
		if (result[i] != 9)
		{
			result[i]++;
			return result;
		}
		else
		{
			while (result[i] == 9)
			{
				result[i] = 0;
				--i;
				if (i < 0)
				{
					result.insert(result.begin(), 1);
					return result;
				}
				if (result[i] != 9)
				{
					result[i]++;
					return result;
				}
			}
		}
	}
	return result;
}
};
