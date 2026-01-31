class Solution {
public:

int32_t countElements(std::vector<int32_t>& pNumbers)
{
	int32_t maxElem = *std::ranges::max_element(pNumbers);
	int32_t minElem = *std::ranges::min_element(pNumbers);

	if (maxElem == minElem)
		return 0;
	
	int32_t counter = 0;

	for (auto& i : pNumbers)
	{
		if (i != maxElem && i != minElem)
			counter++;
	}

	return counter;
}
};
