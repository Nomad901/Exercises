class Solution {
public:
bool existsSquare(int32_t pK, const std::vector<std::vector<int32_t>>& pPrefix, int32_t pThreshold)
{
    int32_t m = pPrefix.size() - 1;
    int32_t n = pPrefix[0].size() - 1;

    for (int32_t i = 0; i <= m - pK; ++i)
    {
        for (int32_t j = 0; j <= n - pK; ++j)
        {
            int32_t sum = pPrefix[i + pK][j + pK] - 
                          pPrefix[i][j + pK] -
                          pPrefix[i + pK][j] + 
                          pPrefix[i][j];
            if (sum <= pThreshold)
                return true;
        }
    }
    return false;
}

int32_t maxSideLength(const std::vector<std::vector<int32_t>>& pMatrix, int32_t pThreshold) 
{
    int32_t m = pMatrix.size();
    int32_t n = pMatrix[0].size();
    
    std::vector<std::vector<int32_t>> prefix(m + 1, std::vector<int32_t>(n + 1, 0));
    
    for (int32_t i = 1; i <= m; ++i)  
    {
        for (int32_t j = 1; j <= n; ++j)  
        {
            prefix[i][j] = pMatrix[i - 1][j - 1] +
                prefix[i - 1][j] +
                prefix[i][j - 1] -
                prefix[i - 1][j - 1];
        }
    }

    int32_t left = 1, right = std::min(m, n);
    int32_t answer = 0;

    while (left <= right)
    {
        int32_t mid = left + (right - left) / 2;

        if (existsSquare(mid, prefix, pThreshold))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
	return answer;
}
};
