class Solution {
public:

int32_t minFlips(std::string pString)
{
	int32_t size = pString.size();
	int32_t result = size;
	int32_t op[2] = { 0, 0 };

	for (int32_t i = 0; i < size; ++i)
		op[(pString[i] ^ i) & 1]++;

	for (int32_t i = 0; i < size; ++i)
	{
		op[(pString[i] ^ i) & 1]--;
		op[(pString[i] ^ (size + i)) & 1]++;
		result = std::min(result, std::min(op[0], op[1]));
	}

	return result;
}


};
