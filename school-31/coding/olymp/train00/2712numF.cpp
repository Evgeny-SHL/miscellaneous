#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

int main() {
    int n, m;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    m = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i] + min(j - i, n - j + i) + a[j] > m) {
                m = a[i] + min(j - i, n - j + i) + a[j];
            }
        }
    }
    cout << m << '\n';
    return 0;
}
