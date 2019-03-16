#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> x;
vector<int> y;
vector<vector<bool> > ok;
vector<int> past;

double len(int i, int j) {
    return sqrt(pow((double)x[i] - x[j], (double)2) + pow((double)y[i] - y[j], (double)2));
}

int mn_x(int i, int j) {
    if (x[i] < x[j]) return i;
    else return j;
}

int mx_x(int i, int j) {
    if (x[i] > x[j]) return i;
    else return j;
}

int mn_y(int i, int j) {
    if (y[i] < y[j]) return i;
    else return j;
}

int mx_y(int i, int j) {
    if (y[i] > y[j]) return i;
    else return j;
}

int main() {
    int n;
    double l;
    cin >> n;
    x.resize(n, 0);
    y.resize(n, 0);
    ok.resize(n);

    for (int i = 0; i < n; ++i) {
        ok[i].resize(n, false);
        cin >> x[i] >> y[i];
    }

    double ans = 0;
    int mn, mx;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j) {
            if (ok[i][j]) continue;
            bool _y = x[i] == x[j];
            if (!_y) {
                mn = mn_x(i, j);
                mx = mx_x(i, j);
            } else {
                mn = mn_y(i, j);
                mx = mx_y(i, j);
            }
            ok[i][j] = true;
            ok[j][i] = true;
            for (int k = j + 1; k < n; ++k) {
                if ((y[k] - y[i]) * (x[j] - x[i]) == (x[k] - x[i]) * (y[j] - y[i])) {
                    ok[i][k] = true;
                    ok[j][k] = true;
                    ok[k][i] = true;
                    ok[k][j] = true;
                    past.push_back(k);
                    if (!_y) {
                        mn = mn_x(k, mn);
                        mx = mx_x(k, mx);
                    } else {
                        mn = mn_y(k, mn);
                        mx = mx_y(k, mx);
                    }
                }
            }
            for (int t = 0; t < past.size(); ++t)
                for (int t1 = t + 1; t1 < past.size(); ++t1) {
                    ok[past[t]][past[t1]] = true;
                    ok[past[t1]][past[t]] = true;
                }
            past.clear();
            ans += len(mn, mx);
      //    cout << i << " " << j << " " << len(mn, mx) << '\n';
        }

    cout << floor(ans + 0.5);

    return 0;
}

