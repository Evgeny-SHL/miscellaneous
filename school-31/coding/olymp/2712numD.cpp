#include <fstream>
#include <deque>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

bool inside(int a, int b, int x, int y, int u, int v) {
    return (min(x, u) <= a && a <= max(x, u) &&
        min(y, v) <= b && b <= max(y, v));
}

map< pair<int, int>, bool > color;
map< pair<int, int>, pair<int, int> > pi, nx;
deque< pair<int, int> > q;
vector< vector<bool> > path;

int x1, y1, u1, v1;
int x2, y2, u2, v2;
int a1, b1, a2, b2;

void bfs(int a1, int b1, int a2, int b2) {
    q.push_back(make_pair(a1, b1));
    while (!q.empty()) {
        pair<int, int> ksi = q.front();
        q.pop_front();
        int x = ksi.first;
        int y = ksi.second;
    //    cout << x << " " << y << '\n';
        color[ksi] = true;
        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                if (dx * dy == 0 && x + dx >= 0 && x + dx <= 101 && y + dy >= 0 && y + dy <= 101 &&
                    !inside(x + dx, y + dy, x1, y1, u1, v1) && !inside(x + dx, y + dy, x2, y2, u2, v2)) {
                    pair<int, int> nw = make_pair(x + dx, y + dy);
                    if (!color[nw]) {
                        pi[nw] = ksi;
                    //    nx[ksi] = nw;
                        if (x + dx == a2 && y + dy == b2) {
                            q.clear();
                            return;
                        }
                        q.push_back(nw);
                        color[nw] = true;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> x1 >> y1 >> u1 >> v1;
    cin >> x2 >> y2 >> u2 >> v2;
    cin >> a1 >> b1 >> a2 >> b2;
    bfs(a1, b1, a2, b2);
    int min_x, min_y, max_x, max_y;
    min_x = min(min(x1, x2), min(u1, u2));
    min_y = min(min(y1, y2), min(v1, v2));
    max_x = max(max(x1, x2), max(u1, u2));
    max_y = max(max(y1, y2), max(v1, v2));
    min_x = min(min_x, min(a1, a2));
    min_y = min(min_y, min(b1, b2));
    max_x = max(max_x, max(a1, a2));
    max_y = max(max_y, max(b1, b2));
    pair<int, int> ksi = make_pair(a2, b2);
    path.resize(102);
    for (int i = 0; i < 102; ++i) {
        path[i].resize(102, false);
    }
    path[ksi.first][ksi.second] = true;
    while (pi.find(ksi) != pi.end()) {
        path[ksi.first][ksi.second] = true;
        nx[pi[ksi]] = ksi;
        ksi = pi[ksi];
        min_x = min(min_x, ksi.first);
        min_y = min(min_y, ksi.second);
        max_x = max(max_x, ksi.first);
        max_y = max(max_y, ksi.second);
    }
    pi[make_pair(a1, b1)] = make_pair(a1, b1);
    nx[make_pair(a2, b2)] = make_pair(a2, b2);
    path[ksi.first][ksi.second] = true;
    for (int i = max_y; i >= min_y; --i) {
        for (int j = min_x; j <= max_x; ++j) {
            if (inside(j, i, x1, y1, u1, v1) || inside(j, i, x2, y2, u2, v2)) {
                cout << "#";
            } else if (path[j][i]) {
                pair<int, int> ksi = make_pair(j, i), prv = pi[ksi], nxt = nx[ksi];
              //  cout << j << " " << i << '\n';
              //  cout << prv.first << " " << prv.second << '\n';
              //  cout << nxt.first << " " << nxt.second << '\n';
                if (j == a1 && i == b1 || j == a2 && i == b2) {
                    cout << "*";
                } else if ((abs(j - prv.first) + abs(j - nxt.first)) == 2) {
                    cout << "-";
                } else if ((abs(i - prv.second) + abs(i - nxt.second)) == 2) {
                    cout << "|";
                } else {
                    cout << "+";
                }
            } else {
                cout << ".";
            }
        }
        cout << '\n';
    }
    return 0;
}
