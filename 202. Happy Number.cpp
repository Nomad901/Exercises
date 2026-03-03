class Solution {
public:
bool isHappy(int32_t pNumber)
{
	std::set<int32_t> history;
	
	while (pNumber > 1)
	{
		std::string tmpStr = std::to_string(pNumber);
		pNumber = 0;

		for (auto& i : tmpStr)
			pNumber += std::pow(i - '0', 2);

		if (history.find(pNumber) != history.end())
			return false;
		history.emplace(pNumber);
	}

	return true;
}
};
