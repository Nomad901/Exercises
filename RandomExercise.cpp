#include <iostream>
#include <format>
#include <vector>
#include <algorithm>

int main()
{
	uint32_t n,k;
	std::cout << "Please, enter N and K numbers: \nN: ";
	std::cin >> n;
	std::cout << "\nK: \n";
	std::cin >> k;
	
	std::vector<uint32_t> vctrN(n + k + 50);  
	std::generate(vctrN.begin(), vctrN.end(), [&n]
		{
			static int32_t counter = 0;
			if (counter < n)
			{
				counter++;
				return counter;
			}
			int32_t number = ++counter % n != 0 ? counter : 0;
			return number;
		});
	std::erase_if(vctrN, [&](auto& value)
		{
			return value == 0;
		});
	std::cout << std::format("Storage: {}\n", vctrN[k]);
	
}
