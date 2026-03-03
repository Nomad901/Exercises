class Solution {
public:
bool containsDuplicate(std::vector<int>& nums)
{
    size_t size = nums.size();
    std::ranges::sort(nums);
    auto it = std::unique(nums.begin(), nums.end());
    nums.erase(it, nums.end());
    return nums.size() != size;
}

};
