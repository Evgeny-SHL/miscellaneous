/*
ID: ugnthes1
PROG: wormhole
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int None = - 1;
const int White = 0;
const int Gray = 1;
const int Black = 2;

vector<int> x, y;
vector<int> color;
vector<bool> foot;
vector< vector<int> > g;
vector< vector<int> > t;
vector< pair<int, int> > p;
int res = 0;
bool cycle;

ifstream fin("wormhole.in");
ofstream fout("wormhole.out");

void dfs(int s, int n, int p, bool step) {
	if (step) {
	//	cout << p << " .. "  << s << "\n";
	} else {
	//	cout << p << " -> "  << s << "\n";
	}
	if (step) {
		foot[s] = true;
	}
	color[s] = Gray;
	for (int i = 0; i < n; ++i) {
		if (step) {
			if (g[s][i]) {
			//	if (color[i] == White) {
					dfs(i, n, s, false);
			//	} else if (color[i] == Gray) {
//
			//	}
			}
		//		if (step[i]) {
		//			cout << s << " -> " << i << " !\n";
		//			cycle = true;
		//			return;
		//		} else {
		//			dfs(i, n, s, false);
		//		}
		//	}
		} else {
			if (t[s][i]) {
				if (foot[i]) {
				//	cout << s << " .. " << i << " !\n";
					cycle = true;
					return;
				} else {
					dfs(i, n, s, true);
				}
			}
			//	if (color[i] == Gray) {
			//		cout << s << " .. " << i << " !\n";
			//		cycle = true;
			//		return;
			//	} else if (color[i] == White) {
			//		dfs(i, n, s, true);
			//	}
		}
	}
	color[s] = Black;
}

bool check(int n) {
	for (int i = 0; i < n / 2; ++i) {
		g[p[i].first][p[i].second] = true;
		g[p[i].second][p[i].first] = true;
	}
//	color.assign(n, White);
	for (int i = 0; i < n; ++i) {
		color.assign(n, White);
		foot.assign(n, false);
		if (color[i] == White) {
		//	cout << "\n";
			dfs(i, n, None, true);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
		//	cout << (g[i][j]) << " ";
		//	fout << g[i][j];
		}
	//	cout << "\n";
	}
//	fout << "\n";
//	cout << cycle << "\n";
//	cout << "\n";
	for (int i = 0; i < n / 2; ++i) {
		g[p[i].first][p[i].second] = false;
		g[p[i].second][p[i].first] = false;
	}
}

void gen(int n, int k, int mask, int ind) {
	if (k != 0) {
		for (int i = 0; i < n; ++i) {
			if ((mask & (1 << i)) == 0) {
				int nmask = mask | (1 << i);
				for (int j = max(ind + 1, i + 1); j < n; ++j) {
					if ((nmask & (1 << j)) == 0) {
						int cmask = nmask | (1 << j);
						p.push_back(make_pair(i, j));
						gen(n, k - 2, cmask, j);
						p.pop_back();
					}
				}
			}
		}
	} else {
		cycle = false;
		check(n);
		res += (int)cycle;
	}
}

int main() {

    int n;

    fin >> n;
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; ++i) {
		fin >> x[i] >> y[i];
	}

	g.resize(n);
	t.resize(n);
	for (int i = 0; i < n; ++i) {
		g[i].assign(n, false);
		t[i].assign(n, false);
	}

	for (int i = 0; i < n; ++i) {
		int to = i;
		for (int j = 0; j < n; ++j) {
			if (i != j && y[i] == y[j] && x[i] < x[j] && (i == to || x[j] < x[to])) {
				to = j;
			}
		}
		if (to != i) {
			t[i][to] = true;
		}
	}

	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << g[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/

	gen(n, n, 0, -1);

	fout << res << "\n";

    return 0;
}