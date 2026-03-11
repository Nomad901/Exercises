class Solution {
public:
int32_t bitwiseComplement(int32_t pNumber)
{
	std::bitset<32> numberInBit(pNumber);
	int32_t count = numberInBit.count();
	numberInBit.flip();
	std::string str = numberInBit.to_string();
	int32_t index = str.find_first_of('0');
	if (index == std::string::npos)
		index = 32 - count - 1;
	str.erase(0, index);
	int32_t result = 0;
	if (!str.empty())
		result = std::stoi(str, 0, 2);
	return result;
}

};
