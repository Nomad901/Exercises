#include <iostream>
#include<vector>

int t[10000];

int x(int n) {
    if (n == 1) return 1;
    if (n > 10000) return 1 + x(n >> 1) + x(n - 1);
    if (t[n])
        return t[n];
    else {
        t[n] = 1 + x(n >> 1) + x(n - 1);
        return t[n];
    }
}

int make_sequence(int n) {
    return x(n >> 1) + 1;
}



int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}