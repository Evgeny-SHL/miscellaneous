#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> a;

int bin_left(int x, int l, int r) {
	if (a[1] == x) {
		return 1;
	}
	while (l + 1 < r) {
		int m = (r + l) / 2;
		if (a[m] >= x) {
			r = m;
		} else {
			l = m;
		}
	}
	if (a[r] != x) {
		return 0;
	}
	return r;
}

int bin_right(int x, int l, int r) {
	if (a[r] == x) {
		return r;
	}
	while (l < r - 1) {
		int m = (r + l) / 2;
		if (a[m] > x) {
			r = m;
		} else {
			l = m;
		}
	}
	if (a[l] != x) {
		return 0;
	}
	return l;
}

int main() {
	int n, q, l, r, x;

	fin >> n >> q;

	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		fin >> a[i];
	}

	for (int i = 1; i <= q; ++i) {
		fin >> x;
		l = bin_left(x, 1, n);
		r = bin_right(x, 1, n);
		if (l != 0) {
			fout << l << " " << r << "\n";
		} else {
			fout << "0\n";
		}
	}

	return 0;
}