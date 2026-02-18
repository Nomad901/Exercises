class Solution {
public:
bool hasAlternatingBits(int32_t pNumber)
{
	std::bitset<32> numberInBits(pNumber);
	std::string str = numberInBits.to_string();
	size_t index = str.find_first_of('1');
	str.erase(0, index);

	for (size_t i = 0; i < str.size() - 1; ++i)
	{
		if (str[i] == str[i + 1])
			return false;
	}

	return true;
}
};
