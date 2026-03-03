class Solution {
public:
    vector<vector<int32_t>> generate(int32_t pNumRows)
    {
        std::vector<std::vector<int32_t>> result;
        result.reserve(pNumRows);
        result.push_back({1});

        for (int32_t i = 1; i < pNumRows; ++i)
        {
            std::vector<int32_t> tmpVec = {1};
            tmpVec.reserve(result[i - 1].size());
            for (int32_t j = 1; j < result[i - 1].size(); ++j)
                tmpVec.push_back(result[i-1][j-1] + result[i - 1][j]);
            tmpVec.push_back(1);
            result.push_back(tmpVec);
        }
        return result;
    }
};
