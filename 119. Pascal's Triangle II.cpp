class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        std::vector<std::vector<int32_t>> result;
        result.reserve(rowIndex);
        result.push_back({1});

        for (int32_t i = 1; i < rowIndex + 1; ++i)
        {
            std::vector<int32_t> tmpVec = {1};
            tmpVec.reserve(result[i - 1].size());
            for (int32_t j = 1; j < result[i - 1].size(); ++j)
                tmpVec.push_back(result[i-1][j-1] + result[i - 1][j]);
            tmpVec.push_back(1);
            result.push_back(tmpVec);
        }
        return result.back();
    }
};
