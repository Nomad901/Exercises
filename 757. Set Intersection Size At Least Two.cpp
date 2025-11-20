#include <iostream>
#include <format>
#include <exception>
#include <string>
#include <stdexcept>
#include <array>
#include <vector>
#include <cmath>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>
#include <unordered_set>
#include <set>

//std::pair<int32_t, int32_t> getRangeOfNumbers(const std::vector<int32_t>& pRangeOfNums, bool pFromEnd)
//{
//	std::array<int32_t, 2> rangeOfNumbers { 0, 0 };
//	size_t rangeOfNumbersIndex = 1;
//
//	for (size_t i = 0; i < pRangeOfNums.size(); ++i)
//	{
//		if(pFromEnd)
//			rangeOfNumbers[rangeOfNumbersIndex] = pRangeOfNums[pRangeOfNums.size() - 1] - i;
//		else 
//			rangeOfNumbers[rangeOfNumbersIndex] = pRangeOfNums[0] + i;
//
//		if (rangeOfNumbersIndex == 0)
//			break;
//		rangeOfNumbersIndex--;
//	}
//
//	return std::make_pair(rangeOfNumbers[0], rangeOfNumbers[1]);
//}

std::vector<int32_t> getRangeOfNumbers(const std::vector<int32_t>& pRangeOfNums)
{
	std::vector<int32_t> rangeOfNumbers;
	rangeOfNumbers.reserve(pRangeOfNums.size());

	for (size_t i = pRangeOfNums[0]; i < pRangeOfNums[1]; ++i)
	{
		rangeOfNumbers.push_back(i);
	}

	return rangeOfNumbers;
}

bool numberInTheRange(const std::pair<int32_t, int32_t>& pRange, int32_t pNumber)
{
	return pNumber >= pRange.first && pNumber <= pRange.second;
}

uint32_t getNumberOfMatches(const std::vector<std::vector<int32_t>>& pRangesOfNumbers, 
							const std::pair<int32_t, int32_t>& pInterval)
{
	uint32_t numberOfMatches = 0;

	for (auto& i : pRangesOfNumbers)
	{
		
	}

	return numberOfMatches;
}

std::pair<int32_t, int32_t> getProperRangeOfNumbers(const std::vector<int32_t>& pRangeOfNumbers,
													const std::vector<int32_t>& pIntervals)
{
	
}

int32_t intersectionSizeTwo(const std::vector<std::vector<int32_t>>& pIntervals)
{
	std::vector<int32_t> intervals;
	intervals.reserve(pIntervals.size() * 2);


	return intervals.size();
}

int32_t main()
{
	std::vector<std::vector<int32_t>> intervals =
	{
		{1, 3},
		{1, 4},
		{2, 5}, 
		{3, 5}
	};

	std::cout << std::format("Intervals result: {}\n", intersectionSizeTwo(intervals));
}
