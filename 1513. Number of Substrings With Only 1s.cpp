#include <iostream>
#include <format>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <numeric>
#include <functional>
#include <assert.h>

int64_t countNumber(std::string_view pStringOfNumbers, std::string_view pNumber)
{
	if (pNumber.size() == 0 || pStringOfNumbers.size() == 0)
		return 0;
	
	auto getSubString = [&](size_t& pIndex) -> std::string
		{
			std::string subString;

			for (size_t i = pIndex; i < pStringOfNumbers.size(); ++i)
			{
				if (pStringOfNumbers[i] == '1')
					subString.push_back('1');
				else
				{
					pIndex = i;
					break;
				}
			}

			return subString;
		};

	uint32_t count = 0;
	std::string subString;
	for (size_t i = 0; i < pStringOfNumbers.size(); ++i)
	{
		if (pStringOfNumbers[i] == '1')
		{
			subString = getSubString(i);

		}
	}
}

int32_t numSub(const std::string& pStringOfNumbers)
{
	int64_t counter = 0;
	int64_t checkNumber = 0;
	std::string subString;

	for (size_t i = 0; i < pStringOfNumbers.size(); ++i)
	{
		subString.push_back('1');
		checkNumber = countNumber(pStringOfNumbers, subString);
		if (checkNumber == 0)
			break;
		counter += checkNumber;
	}

	return counter;
}

int32_t main()
{
	std::string numbers = "0110111";
	std::cout << std::format("Num sub return: {}\n", numSub(numbers));
}
