class Solution {
public:
bool containsNearbyDuplicate(std::vector<int>& nums, int32_t k)
{
    std::unordered_set<int> window;
    
    for (int32_t i = 0; i < nums.size(); ++i)
    {
        if (window.find(nums[i]) != window.end())
            return true;
        
        window.insert(nums[i]);
        
        if (window.size() > k)
            window.erase(nums[i - k]);
    }
    return false;
}
};
