class Solution {
public:
int32_t maximizeSquareHoleArea(int32_t pNumberOfHBars, int32_t pNumberOfVBars,
							   std::vector<int32_t>& pHBarsToRemove, std::vector<int32_t>& pVBarsToRemove)
{	
	std::ranges::sort(pHBarsToRemove);
	std::ranges::sort(pVBarsToRemove);

	auto findLongestConsecutive = [](const std::vector<int32_t>& pArray) -> int32_t
		{
			if (pArray.empty())
				return 0;

			int32_t maxLen = 1;
			int32_t curLen = 1;

			for (size_t i = 1; i < pArray.size(); ++i)
			{
				if (pArray[i] == pArray[i - 1] + 1)
					curLen++;
				else
					curLen = 1;
				maxLen = std::max(maxLen, curLen);
			}

			return maxLen;
		};

	
	const int32_t longestConsecutiveHBars = findLongestConsecutive(pHBarsToRemove);
	const int32_t longestConsecutiveVBars = findLongestConsecutive(pVBarsToRemove);
	
	const int32_t maxHBars = longestConsecutiveHBars + 1;
	const int32_t maxVBars = longestConsecutiveVBars + 1;

	const int32_t side = std::min(maxHBars, maxVBars);

	return side * side;
}

};
