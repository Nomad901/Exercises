class Solution {
public:
int32_t minRemoval(std::vector<int32_t>& pNumbers, int32_t pNumber)
{
	std::ranges::sort(pNumbers);
	int32_t size = pNumbers.size();
	
	int32_t left = 0, right = 0;
	int32_t longestWindowSize = 0;

	while (right < size)
	{
		if (static_cast<long long>(pNumbers[right]) <= static_cast<long long>(pNumbers[left]) * 
                                                       static_cast<long long>(pNumber))
		{
			longestWindowSize = std::max(longestWindowSize, right - left + 1);
			right++;
		}
		else
			left++;
	}

	return size - longestWindowSize;
}

};
