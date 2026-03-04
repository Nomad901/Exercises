class Solution {
public:
    string toHex(int num) 
    {
        std::stringstream ss;
        ss << std::hex << num;
        std::string result(ss.str());
        return result;   
    }
};
