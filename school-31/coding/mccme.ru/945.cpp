#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > f;

int main() {
	int c, r;
	int ans = 0;
	cin >> c >> r;
	f.resize(9);
	for (int i = 0; i <= 8; ++i) {
		f[i].resize(10, 0);
	}
	f[r][c] = 1;
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= 8; ++j) {
			if (i != r || j != c) {
				f[i][j] = f[i - 1][j - 1] + f[i - 1][j + 1];
			}
			if (i == 8) {
				ans += f[i][j];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}