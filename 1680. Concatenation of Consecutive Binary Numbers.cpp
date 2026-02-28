class Solution {
public:
int32_t concatenatedBinary(int32_t pNumber)
{
	int32_t mod = 1000000007;
	int64_t result = 0;

	for (int32_t i = 1; i <= pNumber; ++i)
	{
		int32_t bitLength = 0;
		int32_t temp = i;
		while (temp > 0)
		{
			temp >>= 1;
			bitLength++;
		}

		result = ((result << bitLength) | i) % mod;
	}

	return static_cast<int32_t>(result);
}
};
