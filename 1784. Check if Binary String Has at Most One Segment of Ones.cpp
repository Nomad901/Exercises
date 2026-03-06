class Solution {
public:
bool checkOnesSegment(const std::string& pString)
{
	for (size_t i = pString.find_first_of('0'); i < pString.size() - 1; ++i)
	{
		if (pString[i] == '0' && pString[i + 1] == '1')
			return false;
	}
	return true;
}
};
