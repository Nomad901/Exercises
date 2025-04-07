#include <cmath>
#include <list>

class Kata
{
public:
    std::string toFraction(double number);
};

std::string Kata::toFraction(double number) {
    if (number < 0) return "-" + toFraction(-number);
    constexpr double accuracy = 1. / 2000;

    auto fraction = [](const double x) {
        double intpart;
        return modf(x, &intpart);
        };

    std::list<int> list;
    list.push_front(number);
    while (fraction(number) > accuracy) {
        number = 1.0 / fraction(number);
        list.push_front(number);
    }

    if (list.size() == 1) return std::to_string(list.front());
    else {
        int numerator = 1, denominator = 0;
        for (auto i : list) {
            std::swap(numerator, denominator);
            numerator += i * denominator;
        };
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};



int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}