class Solution {
public:
std::vector<int32_t> nextGreaterElement(std::vector<int32_t>& pNumbers1, std::vector<int32_t>& pNumbers2)
{
	std::vector<int32_t> greaterElements(pNumbers1.size());
	
	for (size_t i = 0; i < pNumbers1.size(); ++i)
	{
		int32_t greaterElem = -1;
		auto it = std::ranges::find(pNumbers2, pNumbers1[i]);
		while (it != pNumbers2.end())
		{
			if (*it > pNumbers1[i])
			{
				greaterElem = *it;
				break;
			}
			it++;
		}
		greaterElements[i] = greaterElem;
	}

	return greaterElements;
}
};
