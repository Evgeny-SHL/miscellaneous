#include <vector>
#include <fstream>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
//#include <iostream>
using namespace std;

ifstream cin("wheel.in");
ofstream cout("wheel.out");

/*struct sect {
    int pr, ind;
    sect(int a = 0, ind = 0) {
        pr = a;
        ind = b;
    }
}*/

/*bool comp(sect a, sect b) {
    return (a.pr > b.pr);
}*/

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);

vector<int> f;

int main() {
    int n, a, b, k, mx = 0;
    cin >> n;
    f.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    cin >> a >> b >> k;
    /*for (int v = a; v <= min(b, a + k); v += k) {
        int t;
        if (v % k == 0) {
            t = v / k - 1;
        } else {
            t = v / k;
        }
        mx = max(mx, f[t % n]);
        mx = max(mx, f[((long long)1e9 * n - t) % n]);
    }*/

    int t1, t2;
    if (a % k == 0) {
        t1 = a / k - 1;
    } else {
        t1 = a / k;
    }
    if (b % k == 0) {
        t2 = b / k - 1;
    } else {
        t2 = b / k;
    }
    for (int t = t1; t <= min(t2, t1 + n); ++t) {
        mx = max(mx, f[t % n]);
        mx = max(mx, f[((long long)1e9 * n - t) % n]);
    }

    cout << mx << '\n';
    return 0;
}
