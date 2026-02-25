class Solution {
public:
std::vector<int32_t> sortByBits(std::vector<int32_t>& pArray)
{
	std::ranges::sort(pArray, [](auto& pFirst, auto& pSecond) -> bool
		{
			std::bitset<32> first(pFirst);
			std::bitset<32> second(pSecond);

			auto firstCount = first.count();
			auto secondCount = second.count();

			if (firstCount != secondCount)
				return firstCount < secondCount;

			return pFirst < pSecond;
		});
	return pArray;
}
};
