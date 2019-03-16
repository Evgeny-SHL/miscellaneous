#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > f;

int main() {
	int n, m, x;
	cin >> n >> m;
	f.resize(n + 1);
	for (int i = 0; i <= n; ++i) {
		f[i].resize(m + 1, 1000);
	}
	cin >> f[1][1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i + j != 2) {
				cin >> x;
				f[i][j] = x + min(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	cout << f[n][m] << '\n';
	return 0;
}