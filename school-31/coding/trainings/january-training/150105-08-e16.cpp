#include <fstream>
#include <vector>
using namespace std;

struct edge {
    long long u, w;
    edge(long long a, long long b) {
        u = a;
        w = b;
    }
};

vector< vector<edge> > g;
vector< vector<long long> > d;

ifstream cin("kpath.in");
ofstream cout("kpath.out");

long long INF = (long long)1.1e18;

void frd_bllmn(long long n, long long m, long long s, long long k) {
    d.resize(k + 1, vector<long long>(n + 1, INF));
    d[0][s] = 0;
    for (int z = 1; z <= k; ++z) {
        for (int v = 1; v <= n; ++v) {
            for (int j = 0; j < (int)g[v].size(); ++j) {
                long long u = g[v][j].u;
                long long w = g[v][j].w;
                if (d[z][u] > d[z - 1][v] + w) {
                    d[z][u] = d[z - 1][v] + w;
                }
            //    cout << v << " " << u << " " << w << " " << d[z][v] << '\n';
            }
        }
    }
}

int main() {
    long long n, m, k, s, v, u, w;
    cin >> n >> m >> k >> s;
    g.resize(n + 1);
    for (int j = 1; j <= m; ++j) {
        cin >> v >> u >> w;
        g[v].push_back(edge(u, w));
    }
    frd_bllmn(n, m, s, k);
    for (int v = 1; v <= n; ++v) {
        if (d[k][v] == INF) {
            cout << -1 << '\n';
        } else {
            cout << d[k][v] << '\n';
         }
    }
    return 0;
}
