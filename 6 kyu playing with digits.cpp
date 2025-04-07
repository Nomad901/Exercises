#include <iostream>
#include<vector>

class DigPow
{
public:
    static int digPow(int n, int p) {
        std::string tmpFN = std::to_string(n);
        unsigned long long powNum = 0;
        int counter = 0;
        std::vector<int> vcStr;

        std::string e = "1";
        for (int i = 0; i < tmpFN.size() - 1; i++) { e.push_back('0'); }
        unsigned long long stoi_ = stoi(e);
        for (int i = 0; i < e.size(); i++)
        {
            counter = n / stoi_ % 10;
            vcStr.push_back(counter);
            stoi_ /= 10;
        }
        counter = 0;

        for (int i = p; ; i++)
        {
            powNum += pow(vcStr[counter], p);
            counter++; p++;
            if (counter == vcStr.size()) { break; }
        }

        counter = 0;
        for (int i = 0; ; i++)
        {
            counter = n * i;
            if (counter == powNum) return i;
            else if (counter > powNum) return -1;
        }

        return counter;
    }
};




int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}