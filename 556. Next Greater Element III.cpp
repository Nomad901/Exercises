class Solution {
public:
 int32_t nextGreaterElement(int32_t pNumber)
{
	std::string numberInString = std::to_string(pNumber);
	std::vector<int32_t> subNumber;
	subNumber.reserve(numberInString.size());

	int32_t sizeString = numberInString.size();
	for (size_t i = sizeString - 1; i >= 1; --i)
	{
		int32_t leftNumber = numberInString[i - 1] - '0';
		int32_t rightNumber = numberInString[i] - '0';
		subNumber.push_back(rightNumber);
		numberInString.erase(i);
		if (rightNumber > leftNumber)
		{
			subNumber.push_back(leftNumber);
			numberInString.erase(i - 1);
			break;
		}
	}
	if (subNumber.empty())
		return -1;

	auto itFirstNumber = subNumber.end() - 1;
	auto itSecondNumber = std::ranges::find_if(subNumber, [&itFirstNumber](int32_t pNumber) -> bool
		{
			return pNumber > *itFirstNumber;
		});
		if (itSecondNumber == subNumber.end())
		return -1;
	std::swap(*itFirstNumber, *itSecondNumber);

	numberInString += std::to_string(subNumber.back());
	subNumber.pop_back();
	std::ranges::sort(subNumber);
	for (auto& digit : subNumber)
	{
		numberInString += std::to_string(digit);
	}
    	long long int32Max = std::numeric_limits<int32_t>::max();
	if (std::stoll(numberInString) > int32Max)
		return -1;
	return std::stoi(numberInString);
}
};
