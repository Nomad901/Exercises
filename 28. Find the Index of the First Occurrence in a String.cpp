class Solution {
public:
int32_t strStr(std::string pOriginal, std::string pSubString)
{
    if (pSubString.size() > pOriginal.size())
        return -1;
    for (size_t i = 0; i < pOriginal.size() - pSubString.size() + 1; ++i)
    {
        std::string tmpSubString = pOriginal.substr(i, pSubString.size());

        if (tmpSubString == pSubString)
            return i;
    }
    return -1;
}
};
