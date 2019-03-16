#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("ant.in");
ofstream fout("ant.out");

vector<int> x, ans, b;
int c;

void init(int n) {
	c = (int)sqrt(n);
	b.assign(n / c + 1, -1);
	for (int i = n; i >= 1; --i) {
		b[i / c] = x[i];
	}
}

int fnd_ant(int p, int n) {
	int ind = -1;
	int block = -1;
	int l;
	int r;
	for (int i = 0; i <= n / c; ++i) {
		if (b[i] != -1 && b[i] <= p) {
			block = i;
		}
	}
//	cout << p << " " << block << "\n";
	if (block == -1) {
		return ind;
	}
	l = max(1, block * c);
	r = min(n, (block + 1) * c - 1);
	for (int i = r; i >= l; --i) {
		if (x[i] != -1 && x[i] <= p) {
			ind = i;
			break;
		}
	}
//	cout << p << " " << block << " " << ind << " " << x[ind] << "\n";
	b[block] = -1;
	x[ind] = -1;
	for (int i = l; i <= r; ++i) {
		if (x[i] != -1) {
			b[block] = x[i];
			break;
		}
	}
//	cout << "..." << b[block] << "\n";
	return ind;
}

int main() {
	int n, m, p, ind;

	fin >> n >> m;
	x.resize(n + 1);
	ans.assign(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		fin >> x[i];
	}
	init(n);
	for (int i = 1; i <= m; ++i) {
		fin >> p;
		ind = fnd_ant(p, n);
		if (ind != -1) {
			ans[ind] = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		fout << ans[i] << "\n";
	}

	return 0;
}
