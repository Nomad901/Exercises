/*
	An inquisitive girl named Varvara clearly improved her understanding of
	combinatorial mathematics over the past year: 
	this time she counted all six-digit decimal numbers containing exactly 0 < K < 7 even digits,
	and ended up with a six-digit number as the result. 
	What is the value of K?
	In your answer, specify the number of numbers corresponding to this value of K
*/

auto getVarvarasShit(int32_t pK) -> std::unordered_map<uint32_t, int64_t>
{
	std::unordered_map<uint32_t, int64_t> result;
	result.reserve(pK);
	for (size_t i = 1; i < pK; i++)
	{
		result.emplace(i, 0);
	}

	int32_t maxNumber = 1;
	int32_t minNumber = 1;
	for (size_t i = 0; i < pK; ++i)
	{
		maxNumber *= 10;
		if (i < pK - 1)
			minNumber *= 10;
	}

	for (size_t i = minNumber; i < maxNumber - 1; ++i)
	{
		std::string numInStr = std::to_string(i);
		int32_t count = std::ranges::count_if(numInStr, [](char pChar)
			{
				return (pChar + '0') % 2 == 0;
			});
		result[count]++;
	}
	return result;
}

int32_t main()
{
	auto result = getVarvarasShit(6);
	for (auto& [key, value] : result)
	{
		std::cout << std::format("{} : {}\n", key, value);
	}
}
