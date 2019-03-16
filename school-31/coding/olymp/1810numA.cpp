#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct cell {
    int i, j;
    cell(int a = 0, int b = 0) {
        i = a;
        j = b;
    }
};

vector<vector<int> > mc;
vector<vector<bool> > cl;
vector<vector<int> > ds;
vector<vector<cell> > fr;
vector<vector<bool> > pt;
queue<cell> q;
const int INF = 10e6;

int bfs(int i_s, int j_s, int i_f, int j_f, int n) {
//  cout << "OK" << '\n';
    q.push(cell(i_s, j_s));
    cell ksi;
    cl[i_s][j_s] = true;
    ds[i_s][j_s] = 0;
    int i, j;
    while (!q.empty()) {
        ksi = q.front();
        q.pop();
        i = ksi.i;
        j = ksi.j;
        cl[i][j] = true;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                if (i + di < 0 || i + di >= n || j + dj < 0 || j + dj >= n || (abs(di) + abs(dj) == 2)) continue;
                if (!cl[i + di][j + dj] && mc[i][j] != -1) {
                    fr[i + di][j + dj] = ksi;
                    ds[i + di][j + dj] = ds[i][j] + 1;
                    q.push(cell(i + di, j + dj));
                    cl[i + di][j + dj] = true;
                }
            }
        }
    }
    return ds[i_f][j_f];
}

int main() {
    int n;
    string x;
    int i_s, i_f, j_s, j_f;

    cin >> n;
    mc.resize(n);
    cl.resize(n);
    ds.resize(n);
    fr.resize(n);
    pt.resize(n);
    for (int i = 0; i < n; ++i) {
        mc[i].resize(n);
        cl[i].resize(n);
        ds[i].resize(n);
        fr[i].resize(n);
        pt[i].resize(n);
        cin >> x;
        for (int j = 0; j < n; ++j) {
            cl[i][j] = false;
            ds[i][j] = INF;
            fr[i][j] = cell(-1, -1);
            pt[i][j] = false;
            switch(x[j]) {
                case '.':
                    mc[i][j] = 0;
                    break;
                case 'O':
                    mc[i][j] = -1;
                    break;
                case 'X':
                    i_f = i;
                    j_f = j;
                    break;
                case '@':
                    i_s = i;
                    j_s = j;
                    mc[i][j] = 1;
                    break;
            }
        }
    }

    int dist = bfs(i_s, j_s, i_f, j_f, n);
    if (dist == INF) cout << "N";
    else {
        cout << "Y" << '\n';
        cell ksi = cell(i_f, j_f);
        while (ksi.i != i_s || ksi.j != j_s) {
            pt[ksi.i][ksi.j] = true;
        //    cout << ksi.i << " " << ksi.j << " -> ";
            ksi = fr[ksi.i][ksi.j];
        //    cout << ksi.i << " " << ksi.j << '\n';
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pt[i][j]) cout << "+";
                else if (mc[i][j] == 0) cout << ".";
                else if (mc[i][j] == -1) cout << "O";
                else if (mc[i][j] == 1) cout << "@";
            }
            cout << '\n';
        }
    }

    return 0;
}
