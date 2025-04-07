#include <string>
#include <vector>

std::vector<std::string> rotate(const std::string& s) {
    if (s != " " || s.size() != 0)
    {
        std::string temp_of_s = s;
        std::vector<std::string> vector_of_strings;

        for (size_t i = 0; i < s.size(); ++i)
        {
            temp_of_s.push_back(temp_of_s[0]);
            temp_of_s.erase(begin(temp_of_s));
            vector_of_strings.push_back(temp_of_s);
        }
        return vector_of_strings;
    }

    return {};
}


int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}