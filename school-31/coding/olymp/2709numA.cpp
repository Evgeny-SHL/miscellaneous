#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n);

    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }

    int k = 0;
    bool f;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            f = true;
            if (i > 0) f = f and (a[i][j] > a[i - 1][j]);
            if (i < n - 1) f = f and (a[i][j] > a[i + 1][j]);
            if (j > 0) f = f and (a[i][j] > a[i][j - 1]);
            if (j < m - 1) f = f and (a[i][j] > a[i][j + 1]);
            if (f) ++k;
        }
    }

    cout << k;

    return 0;
}
