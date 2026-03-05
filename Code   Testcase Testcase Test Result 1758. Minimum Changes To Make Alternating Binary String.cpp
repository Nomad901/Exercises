class Solution {
public:
int32_t minOperations(std::string pString)
{
	int32_t firstCounter = 0;
	int32_t secondCounter = 0;

	for (size_t i = 0; i < pString.size() - 1; i += 2)
	{
		if (pString[i] == '1' && pString[i + 1] == '0')
			firstCounter += 2;
		else if (pString[i] == '0' && pString[i + 1] == '1')
			secondCounter += 2;
		else
		{
			firstCounter++; 
			secondCounter++;
		}
	}
	if (pString.size() % 2 != 0)
	{
		if (pString.back() == '1')
			firstCounter++;
		else
			secondCounter++;
	}

	return std::min(firstCounter, secondCounter);
}
};
