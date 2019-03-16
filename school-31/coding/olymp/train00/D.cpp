#include <fstream>
using namespace std;

ifstream cin("missions.in");
ofstream cout("missions.out");

int main() {
    long long n, x, y;
    long long p = 0, q = 0;
    long long i1 = 0, i2 = 0;
    long long m1 = 0, m2 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        if (x > m1) {
            m1= x;
            p = y;
            i1 = i;
        }
        if (y > m2) {
            m2 = y;
            q = x;
            i2 = i;
        }
    }

    if (i1 == i2) {
        cout << m1 + m2 << '\n';
        cout << i1 << " ";
    } else if (p <= q) {
        cout << m1 + m2 + p << '\n';
        cout << i1 << " " << i2 << " ";
    } else {
        cout << m1 + m2 + q << '\n';
        cout << i2 << " " << i1 << " ";
    }
    for (int i = 1; i <= n; ++i) {
        if (i == i1 || i == i2) {
            continue;
        } else {
            cout << i << " ";
        }
    }
    cout << '\n';

    return 0;
}
