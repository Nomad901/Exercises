class Solution {
public:
    int32_t searchInsert(const std::vector<int32_t>& pNumbers, int32_t pTarget) {
        auto it = std::ranges::find(pNumbers, pTarget);
        if (it != pNumbers.end())
            return it - pNumbers.begin();
        
        auto it2 = std::lower_bound(pNumbers.begin(), pNumbers.end(), pTarget);
        return it2 - pNumbers.begin();
    }
};
