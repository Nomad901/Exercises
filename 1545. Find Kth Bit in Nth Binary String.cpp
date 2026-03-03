class Solution {
public:
char findKthBit(int32_t pLengthStr, int32_t pDesiredNumber)
{
	if (pLengthStr == 1)
		return '0';

	int32_t length = (1 << pLengthStr) - 1;
	int32_t middle = length / 2 + 1;
	if (pDesiredNumber == middle)
		return '1';
	if (pDesiredNumber < middle)
		return findKthBit(pLengthStr - 1, pDesiredNumber);
	else
	{
		int32_t newPos = length - pDesiredNumber + 1;
		char ch = findKthBit(pLengthStr - 1, newPos);
		return ch == '0' ? '1' : '0';
	}
}
};
