#include <fstream>
#include <vector>
using namespace std;

vector<long long> to, fr, wg;
vector< vector<long long> > d;

ifstream cin("kpath.in");
ofstream cout("kpath.out");

long long INF = (long long)1.1e18;

void frd_bllmn(long long n, long long m, long long s, long long k) {
    d.resize(k + 1, vector<long long>(n + 1, INF));
    d[0][s] = 0;
    for (int z = 1; z <= k; ++z) {
        for (int v = 1; v <= n; ++v) {
            for (int j = 1; j <= m; ++j) {
                if (to[j] != v) {
                    continue;
                }
                if (d[z][v] > d[z - 1][fr[j]] + wg[j]) {
                    d[z][v] = d[z - 1][fr[j]] + wg[j];
                }
            }
        }
    }
}

int main() {
    long long n, m, k , s;
    cin >> n >> m >> k >> s;
    fr.resize(m + 1);
    to.resize(m + 1);
    wg.resize(m + 1);
    for (int j = 1; j <= m; ++j) {
        cin >> fr[j] >> to[j] >> wg[j];
    }
    frd_bllmn(n, m, s, k);
    for (int v = 1; v <= n; ++v) {
        if (v == s || d[k][v] == INF) {
            cout << -1 << '\n';
        } else {
            cout << d[k][v] << '\n';
         }
    }
    return 0;
}
