#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const long long bInf = (long long)(1e18 + 3);
const int sInf = (int)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;
const int Root = 1;
const int White = 0;
const int Gray = 1;
const int Black = 2;

bool cycled;
bool full;
int to;
vector< vector<int> > g;
vector<int> color;
vector<int> mrsh;
vector<int> ans;

void dfs(int u) {
	mrsh.push_back(u);
    color[u] = Gray;
    for (int v: g[u]) {
        if (color[v] == White) {
            dfs(v);
        } else if (color[v] == Gray) {
            mrsh.push_back(v);
            cycled = true;
            return;
        }
        if (cycled) {
            return;
        }
    }
    color[u] = Black;
}

void print_cycle() {
	int s = mrsh.back();
	int v;
	int len;
	mrsh.pop_back();
	ans.push_back(s);
    while (mrsh.size() > 0) {
        v = mrsh.back();
        mrsh.pop_back();
        if (v == s) {
			break;
        }
        ans.push_back(v);
    }
	len = (int)ans.size();
	for (int i = len - 1; i >= 0; --i) {
		cout << ans[i] << " ";
	}
    cout << "\n";
}

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    srand(time(0));
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

    int n, m, u, v;

    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    color.assign(n + 1, White);
    cycled = false;
    full = false;
    to = None;
    for (int u = 1; u <= n; ++u) {
        mrsh.clear();
        if (color[u] == White) {
            dfs(u);
        }
        if (cycled) {
            cout << "YES\n";
            print_cycle();
            break;
        }
    }
    if (!cycled) {
        cout << "NO\n";
    }

    return 0;
}