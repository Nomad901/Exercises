class Solution {
public:
std::vector<std::string> readBinaryWatch(int32_t pTurnedOn)
{
	std::vector<std::string> result;

	for (int32_t hour = 0; hour < 12; ++hour)
	{
		for (int32_t minute = 0; minute < 60; ++minute)
		{
			if (getOnesInNumberBinary(hour) + getOnesInNumberBinary(minute) == pTurnedOn)
			{
				std::string resultStr = std::format("{}:{}", hour, (minute < 10 ? "0" + std::to_string(minute) :
																						std::to_string(minute)));
				result.push_back(resultStr);
			}
		}
	}

	return result;
}

private:
int32_t getOnesInNumberBinary(int32_t pNumber)
{
	std::bitset<32> numberBinary(pNumber);
	return (int32_t)numberBinary.count();
}
};
