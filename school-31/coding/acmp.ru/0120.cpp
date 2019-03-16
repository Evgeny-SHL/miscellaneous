#include <fstream>
#include <vector>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector< vector<int> > f;

int main() {

	int n, m, x;

	cin >> n >> m;
	f.resize(n + 1);

	for (int i = 0; i <= n; ++i) {
		f[i].resize(m + 1, 0);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> x;
			if (i == 1) {
				f[i][j] = x + f[i][j - 1];
			} else if (j == 1) {
				f[i][j] = x + f[i - 1][j];
			} else {
				f[i][j] = x + min(f[i - 1][j], f[i][j - 1]);
			}
		}
	}

	cout << f[n][m] << '\n';

	return 0;
}