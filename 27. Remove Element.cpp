class Solution {
public:
int32_t removeElement(std::vector<int32_t>& pNumbers, int32_t pNumber)
{
	int32_t k = 0;

	for (int32_t i = 0; i < pNumbers.size(); ++i)
	{
		if (pNumbers[i] != pNumber)
		{
			pNumbers[k] = pNumbers[i];
			++k;
		}
	}
	return k;
}
};
