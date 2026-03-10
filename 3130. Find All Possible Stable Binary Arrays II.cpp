class Solution {
public:
int32_t numberOfStableArrays(int32_t pNumberOfZero, int32_t pNumberOfOne, int32_t pLimit)
{
	for (int32_t i = 0; i <= pNumberOfZero; ++i)
		std::memset(dp[i], 0, (pNumberOfOne + 1) * 2 * sizeof(long long));

	const int32_t limitOfZeros = std::min(pNumberOfZero, pLimit);
	const int32_t limitOfOnes = std::min(pNumberOfOne, pLimit);
	
	for (int32_t i = 0; i <= limitOfZeros; ++i)
		dp[i][0][0] = 1;
	for (int32_t i = 0; i <= limitOfOnes; ++i)
		dp[0][i][1] = 1;

	for (int32_t i = 1; i <= pNumberOfZero; ++i)
	{
		for (int32_t j = 1; j <= pNumberOfOne; ++j)
		{
			long long& dp0 = dp[i][j][0];
			dp0 = dp[i - 1][j][0] + dp[i - 1][j][1];
			if (i > pLimit)
				dp0 += mod - dp[i - pLimit - 1][j][1];
			if (dp0 >= mod)
				dp0 %= mod;

			long long& dp1 = dp[i][j][1];
			dp1 = dp[i][j - 1][0] + dp[i][j - 1][1];
			if (j > pLimit)
				dp1 += mod - dp[i][j - pLimit - 1][0];
			if (dp1 >= mod)
				dp1 %= mod;
		}
	}

	return (dp[pNumberOfZero][pNumberOfOne][0] + dp[pNumberOfZero][pNumberOfOne][1]) % mod;
}

private:
const int mod=1e9+7;
long long dp[2001][2001][2];

};
