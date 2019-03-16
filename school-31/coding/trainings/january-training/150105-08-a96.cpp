#include <fstream>
#include <vector>
using namespace std;

ifstream cin("binsearch.in");
ofstream cout("binsearch.out");

vector<long long> a;

int left(long long x, int n) {
    int l = 0;
    int r = n;
    if (x < a[1] || x > a[n]) {
        return -1;
    }
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (x <= a[m]) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

int right(long long x, int n) {
    int l = 1;
    int r = n + 1;
    if (x < a[1] || x > a[n]) {
        return -1;
    }
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (x < a[m]) {
            r = m;
        } else {
            l = m;
        }
    }
    return l;
}

int main() {
    int m, n;
    long long x;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int j = 1; j <= m; ++j) {
        cin >> x;
        cout << left(x, n) << " " << right(x, n) << '\n';
    }
    return 0;
}
