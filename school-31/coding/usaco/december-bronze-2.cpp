#include <fstream>
#include <vector>
using namespace std;

ifstream cin("crosswords.in");
ofstream cout("crosswords.out");

vector< vector<bool> > g;
vector<int> r;
vector<int> c;

int main() {

	int n, m;
	char t;
	int k = 0;

	cin >> n >> m;

	g.resize(n + 3);
	g[0].resize(m + 3, true);
	for (int i = 1; i <= n; ++i) {
		g[i].resize(m + 3, false);
		g[i][0] = true;
		g[i][m + 1] = true;
		g[i][m + 2] = true;
	}
	g[n + 1].resize(m + 3, true);
	g[n + 2].resize(m + 3, true);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> t;
			if (t == '#') {
				g[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (g[i][j - 1] && !g[i][j] && !g[i][j + 1] && !g[i][j + 2]) {
				r.push_back(i);
				c.push_back(j);
				++k;
			} else if (g[i - 1][j] && !g[i][j] && !g[i + 1][j] && !g[i + 2][j]) {
				r.push_back(i);
				c.push_back(j);
				++k;
			}
		}
	}

	cout << k << '\n';
	for (int i = 0; i < k; ++i) {
		cout << r[i] << " " << c[i] << '\n';
	}

	return 0;
}