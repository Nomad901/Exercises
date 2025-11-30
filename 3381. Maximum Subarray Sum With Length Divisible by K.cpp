class Solution {
public:

/*
int64_t maxSubarraySum(std::vector<int32_t>& pNumbers, int32_t pPivotNumber)
{
	int64_t totalSum = LLONG_MIN;
	
	for (size_t i = 0; i < pNumbers.size(); ++i)
	{
		int64_t currentSum = 0;
		for (size_t j = 1; i + j - 1 < pPivotNumber; ++j)
		{
			currentSum += pNumbers[i + j - 1];
			if (j % pPivotNumber == 0)
				totalSum = std::max(totalSum, currentSum);
		}
	}
	
	return totalSum;
}
*/

  auto checkSubarray(const std::vector<int32_t>& pOrigNumbers, const std::vector<int32_t>& pSubarray) -> bool
{
	std::vector<int32_t> checkerSubarray;
	checkerSubarray.reserve(pSubarray.size());

	for (auto& i : pSubarray)
	{
		auto it = std::find(pOrigNumbers.begin(), pOrigNumbers.end(), i);
		checkerSubarray.push_back(std::distance(pOrigNumbers.begin(), it));
	}
	
	std::sort(checkerSubarray.begin(), checkerSubarray.end());

	for (size_t i = 0; i < checkerSubarray.size() - 1; ++i)
	{
		if (checkerSubarray[i + 1] - checkerSubarray[i] != 1)
			return false;
	}

	return true;
}

auto getSubarray(const std::vector<int32_t>& pOrigNumbers, const std::vector<int32_t>& pArray,
				 int32_t pBeginArrayForSubarray, int32_t pEndArrayForSubarray) -> std::vector<int32_t>
{
	assert(pBeginArrayForSubarray >= 0);
	assert(pEndArrayForSubarray < pArray.size());
	assert(pBeginArrayForSubarray <= pEndArrayForSubarray);
	
	std::vector<int32_t> subArray;
	subArray.reserve(pArray.size());

	std::copy((pArray.begin() + pBeginArrayForSubarray), (pArray.begin() + pEndArrayForSubarray + 1), std::back_inserter(subArray));

	return checkSubarray(pOrigNumbers, subArray) ? subArray : std::vector<int32_t>();
}

auto getPairOfIndices(const std::vector<int32_t>& pArray, 
					  int32_t pPivotNumber) -> std::vector<std::pair<int32_t, int32_t>>
{
	std::vector<std::pair<int32_t, int32_t>> vectorOfIndices; 
	vectorOfIndices.reserve(pArray.size());
	
	for (int32_t i = static_cast<int32_t>(std::ssize(pArray) - 1); i >= 0; --i)
	{
		if ((i + 1) % pPivotNumber == 0)
		{
			std::pair<int32_t, int32_t> pairIndices = std::make_pair(0, i);
			vectorOfIndices.push_back(pairIndices);
		}
	}

	return vectorOfIndices;
}

auto getSumOfSubarray(const std::vector<int32_t>& pSubArray) -> int64_t
{
	return std::accumulate(pSubArray.begin(), pSubArray.end(), 0LL);
}

auto maxSubarraySum(std::vector<int32_t>& pNumbers, int32_t pPivotNumbers) -> int64_t
{
	std::vector<int32_t> origNumbers = pNumbers;
	std::sort(pNumbers.begin(), pNumbers.end());
	std::reverse(pNumbers.begin(), pNumbers.end());

	std::vector<std::pair<int32_t, int32_t>> pairOfIndices = getPairOfIndices(pNumbers, pPivotNumbers);
	std::vector<std::vector<int32_t>> storageOfVectors;
	storageOfVectors.reserve(pNumbers.size());
	
	for (auto& [begin, end] : pairOfIndices)
	{
		storageOfVectors.push_back(getSubarray(origNumbers, pNumbers, begin, end));
	}

	std::vector<int64_t> storageOfSums(storageOfVectors.size());
	for (size_t i = 0; i < storageOfSums.size(); ++i)
	{
		storageOfSums[i] = getSumOfSubarray(storageOfVectors[i]);
	}
	
	std::sort(storageOfSums.begin(), storageOfSums.end());

	return storageOfSums[storageOfSums.size() - 1];
}
};
