#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<int> > > d(150);
vector<vector<vector<int> > > from(150);

int main() {
	int n;
	cin >> n;


	for (int i = 0; i < 150; ++i) {
		d[i].resize(1001);
		from[i].resize(1001);
		for (int j = 1; j <= 1000; ++j) {
			d[i][j].resize(1000);
			from[i].resize(1000);
			for (int k = 0; j < 1000; ++k) {
				d[i][j][k] = 0;
				from[i][j][k] = -1;
			}
		}
	}

	for (int j = 1; j < 10; ++j)
		d[1][j][j % n] = 1;

	for (int i = 2; i < 150; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 0; k < n; ++k)
				for (int p = 0; p < 10; ++p)
					if (j > p && d[i - 1][j - p][(k - p + n) % n] == 1) {
						d[i][j][k] = 1;
						from[i][j][k] = p;
					} else
						d[i][j][k] = 0;

	int st = 1;
	for (st = 1; st < 150; ++st)
		if (d[st][n][0] == 1)
			break;

	cout << from[st][n][0];

	return 0;
}