class Solution {
public:
int32_t mirrorDistance(int32_t pNumber)
{
	std::string str = std::to_string(pNumber);
	std::ranges::reverse(str);
	int32_t secondNumber = std::stoi(str);
	return std::abs(pNumber - secondNumber);
}
};
