class Solution {
public:
int32_t minimumDeletions(std::string pString)
{
	int32_t size = pString.length();
	std::vector<int32_t> countA(size, 0);
	int32_t aCount = 0;

	for (int32_t i = size - 1; i >= 0; --i)
	{
		countA[i] = aCount;
		if (pString[i] == 'a')
			aCount++;
	}

	int32_t minDeletitions = size;
	int32_t bCount = 0;
	for (int32_t i = 0; i < size; ++i)
	{
		minDeletitions = std::min(countA[i] + bCount, minDeletitions);
		if (pString[i] == 'b')
			bCount++;
	}

	return minDeletitions;
}
};
