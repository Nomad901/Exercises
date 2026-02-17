class Solution {
public:
bool isPalindrome(std::string pString)
{
    int32_t left = 0, right = pString.size() - 1;

    while (left < right)
    {
        while (left < right && !std::isalnum(pString[left])) ++left;
        while (left < right && !std::isalnum(pString[right])) --right;

        if (std::tolower(pString[left]) != std::tolower(pString[right]))
            return false;

        left++;
        right--;
    }

    return true;
}

};
