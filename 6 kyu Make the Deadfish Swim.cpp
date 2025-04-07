#include <iostream>
#include<vector>

using namespace std;

vector<int> i(string f) {
    vector<int> d = { 0 };
    int com = 0;
    for (auto& q : f) {
        if (q == 'o') {
            d.push_back(d[com]);
            com++;
        }
        if (q == 'i') { d[com] += 1; }
        if (q == 'd') { d[com] -= 1; }
        if (q == 's') { d[com] *= d[com]; }
    }
    d.pop_back();
    for (auto& q : d) {
        cout << q << ',';
    }
    return d;
}



int main()
{
    i("iiiiisoiiiiiiiiisdoiiis");

    return 0;
}