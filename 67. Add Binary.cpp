class Solution {
public:
std::string addBinary(std::string pFirstNumber, std::string pSecondNumber)
{
	std::string result = "";
	int32_t carry = 0;

	std::ranges::reverse(pFirstNumber);
	std::ranges::reverse(pSecondNumber);

	int32_t size = std::max(pFirstNumber.size(), pSecondNumber.size());

	for (size_t i = 0; i < size; ++i)
	{
		int32_t firstNum = i < pFirstNumber.size() ? pFirstNumber[i] - '0' : 0;
		int32_t secondNum = i < pSecondNumber.size() ? pSecondNumber[i] - '0' : 0;

		int32_t total = firstNum + secondNum + carry;
		char c = (total % 2) + '0';
		result.push_back(c);
		carry = total / 2;
	}
		
	if (carry)
		result += '1';

	std::ranges::reverse(result);

	return result;
}
};
