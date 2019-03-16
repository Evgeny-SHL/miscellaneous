#include <fstream>
#include <vector>
using namespace std;

ifstream cin("lcs.in");
ofstream cout("lcs.out");

const int INF = (int) 1e9 + 7;

vector<int> a, b;
vector< vector<int> > d;

void print(int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (a[i] == b[j] && d[i][j] == d[i - 1][j - 1] + 1) {
        print(i - 1, j - 1);
        cout << a[i] << " ";
    } else {
        int a = d[i - 1][j];
        int b = d[i][j - 1];
        int c = d[i - 1][j - 1];
        if (a >= b && a >= c) {
            print(i - 1, j);
        } else if (b >= a && b >= c) {
            print(i, j - 1);
        } else {
            print(i - 1, j - 1);
        }
    }
}

int main() {
    int m, n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    b.resize(m + 1);
    for (int j = 1; j <= m; ++j) {
        cin >> b[j];
    }
    d.resize(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) {
        d[i][0] = 0;
    }
    for (int j = 0; j <= m; ++j) {
        d[0][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            } else {
                int a = d[i - 1][j];
                int b = d[i][j - 1];
                int c = d[i - 1][j - 1];
                d[i][j] = max(a, max(b, c));
            }
        }
    }
    cout << d[n][m] << '\n';
    print(n, m);
    return 0;
}
