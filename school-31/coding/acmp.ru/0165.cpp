#include <fstream>
#include <vector>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector< vector<int> > f, g;

int main() {

	int n, m, x;

	cin >> n >> m;
	f.resize(n + 1);
	g.resize(n + 1);

	for (int i = 0; i <= n; ++i) {
		f[i].resize(m + 1, 0);
		g[i].resize(m + 1, 0);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> g[i][j];
		}
	}

	f[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == n && j == m) {
				continue;
			}
			x = g[i][j];
			if (i + x <= n) {
				if (i + x == n && j == m) {
				//	cout << i << " " << j << '\n';
				}
				f[i + x][j] += f[i][j];
			}
			if (j + x <= m) {
				if (i == n && j + x == m) {
				//	cout << i << " " << j << '\n';
				}
				f[i][j + x] += f[i][j];
			}
		}
	}

/*	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << f[i][j] << " ";
		}
		cout << '\n';
	}

*/	cout << f[n][m] << '\n';

	return 0;
}