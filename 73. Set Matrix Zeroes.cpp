class Solution {
public:
void setZeroes(std::vector<std::vector<int32_t>>& pMatrix)
{
	bool firstColumnHasZero = false;

	for (int32_t row = 0; row < pMatrix.size(); ++row)
	{
		if (pMatrix[row][0] == 0)
			firstColumnHasZero = true;
		for (int32_t col = 1; col < pMatrix[0].size(); ++col)
		{
			if (pMatrix[row][col] == 0)
			{
				pMatrix[row][0] = 0;
				pMatrix[0][col] = 0;
			}
		}
	}

	for (int32_t row = pMatrix.size() - 1; row >= 0; --row)
	{
		for (int32_t col = pMatrix[0].size() - 1; col >= 1; --col)
		{
			if (pMatrix[row][0] == 0 || pMatrix[0][col] == 0)
				pMatrix[row][col] = 0;
		}
		if (firstColumnHasZero)
			pMatrix[row][0] = 0;
	}
}
};
