class Solution {
public:
 bool canMakeArithmeticProgression(std::vector<int32_t>& pArray)
{
		std::unique(pArray.begin(), pArray.end());

	std::sort(pArray.begin(), pArray.end());
	uint32_t previousNumber = 0;
	uint32_t currentNumber = 0;
	for (size_t i = 0; i < pArray.size() - 1; ++i)
	{
		currentNumber = pArray[i + 1] - pArray[i];
		if (previousNumber == 0)
			previousNumber = currentNumber;
		else
		{
			if (previousNumber != currentNumber)
				return false;
		}
	}
	return true;
}
};
