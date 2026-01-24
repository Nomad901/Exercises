class Solution {
public:
 int32_t minPairSum(std::vector<int32_t>& pNumbers)
{
	std::ranges::sort(pNumbers);

	std::vector<uint32_t> sums;
	sums.reserve(pNumbers.size() / 2);

	size_t indexBegin{ 1 }, indexEnd{ pNumbers.size() - 1 };
	for (; indexBegin != pNumbers.size() - 1; ++indexBegin, --indexEnd)
	{
		sums.push_back(pNumbers[indexBegin - 1] + pNumbers[indexEnd]);
	}

	std::ranges::sort(sums);
	return sums.back();
}
};
