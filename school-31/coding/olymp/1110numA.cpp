#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > a;
vector<vector<int> > f;
vector<vector<bool> > c;

int main() {

    int n;
    cin >> n;
    string s;
    a.resize(n);
    f.resize(n);
    c.resize(n);

    for (int i = 0; i < n; ++i) {
        a[i].resize(n);
        f[i].resize(n);
        c[i].resize(n);
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = int(s[j] - '0');
            c[i][j] = false;
        }
    }

    f[0][0] = a[0][0];
    for (int j = 1; j < n; ++j) {
        f[0][j] = f[0][j - 1] + a[0][j];
    }
     for (int i = 1; i < n; ++i) {
        f[i][0] = f[i - 1][0] + a[i][0];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j)
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
    }

//    cout << f[n - 1][n - 1] << '\n';

    c[n - 1][n - 1] = true;
    int i = n - 1, j = n - 1;
    for (int k = 1; k < 2 * n; ++k) {
        if  ((j == 0) || ((i > 0) && (f[i - 1][j] + a[i][j] == f[i][j]))) {
            i -= 1;
        } else {
            j -= 1;
        }
        c[i][j] = true;
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (c[i][j]) cout << "#";
            else cout << "-";
        }
        cout << '\n';
    }


    return 0;
}
