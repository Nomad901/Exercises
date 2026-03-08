class Solution {
public:
std::string findDifferentBinaryString(std::vector<std::string>& pNumbers)
{
	int32_t size = pNumbers.size();
	std::string result(size, '0');

	while (std::find(pNumbers.begin(), pNumbers.end(), result) != pNumbers.end())
	{
		result.push_back('1');
		result.erase(0, 1);
	}

	return result;
}
};
