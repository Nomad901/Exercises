class Solution {
public:
std::string convert(std::string pString, int32_t pNumRows)
{
	if (pNumRows == 1 || pString.size() <= pNumRows)
		return pString;

	std::vector<std::string> stringRows(pNumRows);
	bool goingDownUp = false;

	int32_t currentRow = 0;

	for (auto& c : pString)
	{
		stringRows[currentRow] += c;

		if (currentRow == 0 || currentRow == pNumRows - 1)
			goingDownUp = !goingDownUp;

		currentRow += goingDownUp ? +1 : -1;
 	}

	std::string result;

	for (auto& i : stringRows)
	{
		result += i;
	}
		
	return result;
}
};
