class Solution {
public:
int32_t numSteps(std::string pString)
{
	int32_t result = 0;

	while (pString != "1")
	{
		if (pString.back() == '0')
		{
			pString.pop_back();
		}
		else
		{
			auto it = pString.find_first_of('0');
			if (it != std::string::npos)
			{
				pString.erase(it, 1);
				pString.push_back('0');
			}
			else
			{
				pString.assign(pString.size(), '0');
				pString.insert(pString.begin(), '1');
			}
		}
		result++;
	}

	return result;
}

};
