#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > mc;
vector<int> pra;
vector<int> fr;
vector<int> cl;

void dfs(int v, int st) {
    cl[v] = true;
    for (int i = 0; i < mc[v].size(); ++i) {
        fr[mc[v][i]] = st;
        dfs(mc[v][i], st);
    }
}

int main() {
    int n, x;

    cin >> n;
    mc.resize(n + 1);
    fr.resize(n + 1);
    cl.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        mc[x].push_back(i);
        cl[x] = false;
        if (x == 0) {
            pra.push_back(i);
            fr[x] = 0;
        }
    }

    for (int i = 0; i < pra.size(); ++i) {
        dfs(pra[i], pra[i]);
    }

    for (int i = 1; i <= n; ++i)
        cout << fr[i] << '\n';

    return 0;
}
