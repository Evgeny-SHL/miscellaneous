#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > g;
vector< vector<int> > cm;
vector<int> color;

int num;

void dfs(int v) {
    color[v] = 1;
    cm[num].push_back(v);
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (color[u] == 0) {
            dfs(u);
        }
    }
}

int main() {
    int n, m, v, u;

    cin >> n >> m;

    g.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> v >> u;
        g[v - 1].push_back(u - 1);
        g[u - 1].push_back(v - 1);
    }

    num = 0;

    cm.resize(n + 1);
    color.resize(n + 1, 0);


    for (int v = 0; v < n; ++v) {
        if (color[v] == 0) {
            num++;
            dfs(v);
        }
    }

    cout << num << '\n';
    color.resize(n + 1, 0);
    for (int i = 1; i <= num; ++i) {
        cout << cm[i].size() << '\n';
        for (int j = 0; j < cm[i].size(); ++j) {
            cout << cm[i][j] + 1 << " ";
        }
        cout << '\n';
    }

    return 0;
}
