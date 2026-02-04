class Solution {
public:
long long maxSumTrionic(std::vector<int32_t>& pNumbers)
{
	int32_t size = pNumbers.size();
	long long result = -1E14;
	for (int32_t i = 0; i < size - 1; ++i)
	{
		if (pNumbers[i] > pNumbers[i + 1])
		{
			int32_t left = i;
			long long sum = pNumbers[i];
			while (i < size - 1 && pNumbers[i] > pNumbers[i + 1])
			{
				++i;
				sum += pNumbers[i];
			}
			int32_t right = i;

			int32_t l = left, r = right;
			long long lMax = INT_MIN, rMax = INT_MIN;
			long long lCur = 0, rCur = 0;
			while (l > 0 && pNumbers[l - 1] < pNumbers[l])
			{
				lCur += pNumbers[--l];
				lMax = std::max(lMax, lCur);
			}
			while (r < size - 1 && pNumbers[r] < pNumbers[r + 1])
			{
				rCur += pNumbers[++r];
				rMax = std::max(rMax, rCur);
			}
			if (l != left && r != right)
				result = std::max(result, sum + lMax + rMax);
		}
	}
	return result;
}
};
