class Solution {
public:
    vector<string> cellsInRange(string s) 
    {
        std::vector<std::string> result;
        std::string currentStr = s.substr(0, 2);
        const std::string lastStr = s.substr(s.size() - 2);
        const int32_t startNumber = currentStr[1] - '0';
        const int32_t endNumber = lastStr[1] - '0';

        result.reserve(startNumber * endNumber);

        while (currentStr != lastStr)
        {
            result.push_back(currentStr);
            if(currentStr[1] - '0' == endNumber)
            {
                currentStr[0]++;
                currentStr[1] = startNumber + '0';
            }
            else 
                currentStr[1]++;
        }
        result.push_back(currentStr);

        return result;
    }
};
