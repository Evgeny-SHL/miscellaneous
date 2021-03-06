//#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("diploma.in");ofstream cout("diploma.out");

bool may(long long l, long long w, long long h, long long n) {
    return ((l / w) * (l / h) >= n);
}

int main() {
    long long w, h, n;
    cin >> w >> h >> n;
    long long r = (long long) (n * max(w, h));
    long long l = (long long) (max(w, h));
    int m;
    while (l < r) {
        m = (l + r) / 2;
     //   cout << l << " " << m << " " << r << '\n';
        if (may(m, w, h, n)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
 //   cout << l << " " << m << " " << r << '\n';
    cout << r << '\n';
    return 0;
}
