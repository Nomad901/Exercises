#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <memory>

using namespace std;

std::string password_gen() {
    std::string s;
    std::string for_for = "ABER";
    std::string literals = "/$%*";
    std::string lowercase = "qwer";
    std::string nubmers = "1234";

    int j = std::max(6, rand() % 21);

    for (int i = 0; i < j; i++) {
        int type = rand() % 4;
        switch (type) {
        case 0: s.push_back(for_for[rand() % for_for.size()]); break;
        case 1: s.push_back(lowercase[rand() % lowercase.size()]); break;
        case 2: s.push_back(literals[rand() % literals.size()]); break;
        case 3: s.push_back(nubmers[rand() % nubmers.size()]); break;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        s.pop_back();
    }
    s.push_back(for_for[rand() % for_for.size()]);
    s.push_back(lowercase[rand() % lowercase.size()]);
    s.push_back(literals[rand() % literals.size()]);
    s.push_back(nubmers[rand() % nubmers.size()]);



    if (s.size() > 20) {
        s.resize(20);
    }

    return s;
}


int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {

        for (unsigned i = 0; i < 40; i++) {
            string pwd = password_gen();
            bool lower = any_of(pwd.begin(), pwd.end(), ::islower),
                upper = any_of(pwd.begin(), pwd.end(), ::isupper),
                digit = any_of(pwd.begin(), pwd.end(), ::isdigit),
                length = pwd.size() >= 6 && pwd.size() <= 20;
            if (lower && upper && digit && length)
                printf("%-20s | OK!\n", pwd.c_str());
            else
                printf("%-20s | INVALID\n", pwd.c_str());
        }
    }



    return 0;
}
