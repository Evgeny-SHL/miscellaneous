#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream cin("switches.in");
ofstream cout("switches.out");

vector<int> a, b;
vector<bool> used;
long long ans;
const long long INF = 1e9 + 7;

void cmp(int ind, int n, int m, vector<bool> used) {
    for (int i = ind; i <= n; ++i) {
        if (!used[i]) {
            vector<bool> used_copy(used);
            used_copy[i] = true;
            if (m > 1) {
                cmp(i + 1, n, m - 1, used_copy);
            } else {
                long long mn_a = 0;
                for (int i = 1; i <= n; ++i) {
                    long long mn = INF;
                    for (int j = 1; j <= n; ++j) {
                        if (used_copy[j]) {
                           mn = min(mn, (long long)abs(a[i] - a[j]));
                        }
                    }

                    mn_a += mn;
                }
                ans = min(ans, mn_a);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    used.resize(n + 1, false);
    ans = INF;
    cmp(1, n, m, used);
    cout << ans << '\n';
    return 0;
}
