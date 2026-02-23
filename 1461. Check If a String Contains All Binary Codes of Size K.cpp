class Solution {
public:
bool hasAllCodes(std::string pString, int32_t pTargetNumber)
{
	if (pTargetNumber >= 19)
		return false;

	std::unordered_set<std::string> storageOfStrings;
	storageOfStrings.reserve(std::pow(2, pTargetNumber));

	int32_t stringSize = pString.size();

	for (int32_t i = 0; i < stringSize - pTargetNumber + 1; ++i)
	{
		storageOfStrings.emplace(pString.substr(i, pTargetNumber));
	}

	return storageOfStrings.size() == std::pow(2, pTargetNumber);
}
};
