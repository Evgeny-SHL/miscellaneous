#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int len;
vector<char> a, b;

void _init() {
	len = (int)sqrt(n);
	a.resize(n, '.');
	b.resize((n - 1) / len + 1, '.');
}

void _update(int i, int j, char key) {
	int l = i / len;
	int r = j / len;
	if (r == l) {
		if (b[l] != '.') {
			for (int k = len * l; k < i; ++k) {
				a[k] = b[l];
			}
			for (int k = j + 1; k < min(n, len * (l + 1)); ++k) {
				a[k] = b[l];
			}
		}
		for (int k = i; k <= j; ++k) {
			a[k] = key;
		}
		b[l] = '.';
		return;
	}
	for (int k = l + 1; k < r; ++k) {
		b[k] = key;
	}
	if (b[l] != '.') {
		for (int k = len * l; k < i; ++k) {
			a[k] = b[l];
		}
	}
	for (int k = i; k < len * (l + 1); ++k) {
		a[k] = key;
	}
	b[l] = '.';
	if (b[r] != '.') {
		for (int k = j + 1; k < min(n, len * (l + 1)); ++k) {
			a[k] = b[r];
		}
	}
	for (int k = len * r; k <= j; ++k) {
		a[k] = key;
	}
	b[r] = '.';
}

void _print() {
	for (int i = 0; i < n; ++i) {
		if (b[i / len] != '.') {
		/*	int ind = i / len;
			for (; i < min(n, len * (ind + 1)); ++i) {
				cout << b[ind];
			}
			--i;
		*/	a[i] = b[i / len];
		} //else {
			cout << a[i];
	//	}
	}
}

int main() {
	int m, i, j;
	char color;
	cin >> n >> m;
	_init();
	for (int t = 1; t <= m; ++t) {
		cin >> color >> i >> j;
		_update(i - 1, j - 1, color);
	}
	_print();
	cout << '\n';
	return 0;
}