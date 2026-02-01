class Solution {
public:
std::vector<int32_t> nextGreaterElements(std::vector<int32_t>& pNumbers)
{
	int32_t sizeNumbers = pNumbers.size();
	std::vector<int32_t> greaterElements;
	greaterElements.reserve(pNumbers.size());

	for (int32_t i = 0; i < sizeNumbers; ++i)
	{
		bool foundGreaterNumber = false;
		bool firstTime = true;
		for (int32_t j = i; j < sizeNumbers; ++j)
		{
			if (pNumbers[i] < pNumbers[j])
			{
				greaterElements.push_back(pNumbers[j]);
				foundGreaterNumber = true;
				break;
			}
			if (j + 1 == sizeNumbers && firstTime)
			{
				j = -1;
				firstTime = false;
			}
		}
		if (!foundGreaterNumber)
			greaterElements.push_back(-1);
	}

	return greaterElements;
}

};
