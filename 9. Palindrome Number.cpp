class Solution {
public:
bool isPalindrome(int32_t pNumber) 
{
	if (pNumber < 0)
		return false;

	std::string numberInString = std::to_string(pNumber);
	std::ranges::reverse(numberInString);
	
	if (std::stol(numberInString) == pNumber)
		return true;
	return false;
}

};
