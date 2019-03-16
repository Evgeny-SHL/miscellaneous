//#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector< vector<bool> > b;

//ifstream fin("input.txt");

int main() {
	int n, r, c;
	char t;

	cin >> n;

	r = -1;
	c = -1;
	b.resize(n);
	for (int i = 0; i < n; ++i) {
		b[i].assign(n, false);
		for (int j = 0; j < n; ++j) {
			cin >> t;
			if (t == '#') {
				b[i][j] = true;
				r = i;
				c = j;
			}
		}
	}

	while (r != -1 && c != -1) {
		if (r <= 1 || c <= 0 || c >= n - 1) {
			cout << "NO\n";
			return 0;
		}
		b[r][c] = !b[r][c];
		b[r - 1][c] = !b[r - 1][c];
		b[r - 2][c] = !b[r - 2][c];
		b[r - 1][c - 1] = !b[r - 1][c - 1];
		b[r - 1][c + 1] = !b[r - 1][c + 1];
		if (b[r][c] || b[r - 1][c] || b[r - 2][c] || b[r - 1][c - 1] || b[r - 1][c + 1]) {
			cout << "NO\n";
			return 0;
		}
		r = -1;
		c = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (b[i][j]) {
					r = i;
					c = j;
				}
			}
		}
	}

	cout << "YES\n";

	return 0;
}
