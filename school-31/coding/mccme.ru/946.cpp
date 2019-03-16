#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > f;

int main() {
	int n, m;
	cin >> n >> m;
	f.resize(n + 1);
	for (int i = 0; i <= n; ++i) {
		f[i].resize(m + 1, 0);
	}
	f[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i + j != 2) {
				if (i > 1) {
					f[i][j] += f[i - 2][j - 1];
				}
				if (j > 1) {
					f[i][j] += f[i - 1][j - 2];
				}
			}
		//	cout << f[i][j] << " ";
		}
	//	cout << '\n';
	}
	cout << f[n][m] << '\n';
	return 0;
}