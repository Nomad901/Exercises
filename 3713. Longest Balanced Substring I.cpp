class Solution {
public:
int32_t longestBalanced(std::string pString)
{
	int32_t size = pString.size();
	int32_t result = 0;
	std::vector<int32_t> count(26);
	for (int32_t i = 0; i < size; ++i)
	{
		std::ranges::fill(count, 0);
		for (int32_t j = i; j < size; ++j)
		{
			bool flag = true;
			int32_t ind = pString[j] - 'a';
			count[ind]++;
			for (auto& x : count)
			{
				if (x > 0 && x != count[ind])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				result = std::max(result, j - i + 1);
		}
	}

	return result;
}

};
