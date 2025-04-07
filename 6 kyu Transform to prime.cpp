#include <iostream>
#include<vector>

struct MyStruct
{
    int sieve(int n) {
        if (n == 0 || n == 1) {
            return 0;
        }
        std::vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            int q = i * i;
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        if (prime[n] == true)
        {
            return d;
        }
        else {
            d++;
            n += 1;
            return sieve(n);
        }
    }
    int d = 0;
};



int minimumNumber(std::vector<int> numbers) {
    int j = 0;
    int f;
    for (auto& i : numbers)
    {
        j += i;
    }
    MyStruct w;
    w.d = 0;
    return w.sieve(j);
}
