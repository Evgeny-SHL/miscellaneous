#include <fstream>
#include <vector>
//#include <iostream>
#include <string>
#include <deque>
using namespace std;

ifstream cin("versus.in");
ofstream cout("versus.out");

int main() {
    long long n, k1, k2, a;

    cin >> n;

    k1 = 0;
    k2 = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a % 2 == 1)
            ++k1;
        else
            ++k2;
    }

    cout << k1 * k2 << '\n';

    return 0;
}
