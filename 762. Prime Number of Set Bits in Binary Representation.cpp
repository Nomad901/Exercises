class Solution {
public:
int32_t countPrimeSetBits(int32_t pLeft, int32_t pRight)
{
	uint32_t result = 0;

	while (pLeft <= pRight)
	{
		std::bitset<32> numberInBinary(pLeft);
		if (isPrime(numberInBinary.count()))
			result++;
		pLeft++;
	}

	return result;
}
private:
bool isPrime(int32_t pNumber)
{
	if (pNumber <= 1)
		return false;
	for (size_t i = 2; i * i <= pNumber; ++i)
	{
		if (pNumber % i == 0)
			return false;
	}
	return true;
}
};
