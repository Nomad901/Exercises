class Solution {
public:
    void findAllIndicesOfOne(const std::vector<int32_t>& pNumbers,
                                   std::vector<int32_t>& pIndices)
    {
        for (size_t i = 0; i < pNumbers.size(); ++i)
        {
            if (pNumbers[i] == 1)
                pIndices.push_back(i);
        }
    }

    bool kLengthApart(const std::vector<int32_t>& pNumbers, int32_t pKeyNumber)
     {
        if (std::find(pNumbers.begin(), pNumbers.end(), 1) == pNumbers.end())
		    return true;

        std::vector<int32_t> indices;
        indices.reserve(pNumbers.size());
        findAllIndicesOfOne(pNumbers, indices);

        for (size_t i = 0; i < indices.size() - 1; ++i)
        {
            if ((indices[i + 1] - 1) - indices[i] < pKeyNumber)
                return false;
        }

        return true;
    }
};
