class Solution {
public:
 double champagneTower(int32_t pPoured, int32_t pQueryRow, int32_t pQueryGlass)
{
	std::vector<std::vector<double>> storage(102, std::vector<double>(102));
	storage[0][0] = static_cast<double>(pPoured);

	for (size_t i = 0; i <= pQueryRow; ++i)
	{
		for (size_t j = 0; j <= i; ++j)
		{
			double tmp = (storage[i][j] - 1.0) / 2.0;
			if (tmp > 0.0)
			{
				storage[i + 1][j] += tmp;
				storage[i + 1][j + 1] += tmp;
			}
		}
	}
	return std::min(1.0, storage[pQueryRow][pQueryGlass]);
}


};
