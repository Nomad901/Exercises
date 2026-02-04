class Solution {
public:
int32_t removeDuplicates(std::vector<int32_t>& pNumbers)
{
    if(pNumbers.size() == 0)
        return 0;
    
    int32_t j = 0;
    for(int32_t i = 1; i < pNumbers.size(); ++i)
    {
        if(pNumbers[j] != pNumbers[i])
            pNumbers[++j] = pNumbers[i];
    }
    return j + 1;
}
};
