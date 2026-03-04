class Solution {
public:
int32_t numSpecial(std::vector<std::vector<int32_t>>& pMatrix)
{
	int32_t count = 0;
	for (auto& i : pMatrix)
	{
		auto it = std::find(i.begin(), i.end(), 1);
		if (it != i.end())
		{
			if (std::ranges::count(i, 1) == 1)
			{
				count += specialInAColumn(pMatrix, it - i.begin()) ? +1 : 0;
			}
		}
	}
	return count;
}
private:
bool specialInAColumn(const std::vector<std::vector<int32_t>>& pMatrix, int32_t pIndexColumn)
{
	int32_t count = 0;
	for (auto& i : pMatrix)
	{
		count += i[pIndexColumn] == 1 ? 1 : 0;
		if (count >= 2)
			return false;
	}
	return true;
}
};
