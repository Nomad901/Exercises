#include <vector>

int sumDigNthTerm(int initval, const std::vector<int> patternl, int nthterm) {
    std::cout << initval << ',' << patternl.size() << ',' << nthterm << '\n';
    int counter = initval;
    int counter2 = 0;
    std::vector<int> digits;

    for (size_t i = 0; counter2 < nthterm - 1; )
    {
        counter2++;
        counter += patternl[i];
        if (i == patternl.size() - 1) {
            i = 0;
        }
        else ++i;

    }

    std::string e = "1";
    std::string tmp = std::to_string(counter);
    for (size_t i = 0; i < tmp.size() - 1; i++) { e.push_back('0'); }
    int z = stoi(e);
    for (size_t i = 0; i < tmp.size(); i++)
    {
        int s = counter / z % 10;
        digits.push_back(s);
        z /= 10;
    }

    counter = 0;

    for (auto& i : digits)
    {
        counter += i;
    }

    return counter;
}




int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}