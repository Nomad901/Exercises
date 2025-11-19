class Solution {
public:
    bool isOneBitCharacter(const vector<int>& pBits)
    {
        uint32_t index = 0;
        uint32_t lastElement = pBits.size() - 1;
        uint32_t counter = 0;

        while (index < lastElement)
        {
            if (pBits[index] == 1)
            {
                counter += 2;
                index += 2;
            }
            else
            {
                counter++;
                index++;
            }
        }

        return counter == lastElement;
    }
};
