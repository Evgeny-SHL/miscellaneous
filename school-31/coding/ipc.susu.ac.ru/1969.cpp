#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long Inf = (long long)(1e9 + 7);
vector<long long> x, k, b;
vector<int> ileft, iright, block;
int Len, Amnt;

void init(int n) {
	Len = (int)sqrt(n);
	Amnt = n / Len + 1;
	k.assign(Amnt, 1);
	b.assign(Amnt, 0);
	ileft.assign(Amnt, n);
	iright.assign(Amnt, 1);
	block.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		block[i] = i / Len;
		ileft[block[i]] = min(i, ileft[block[i]]);
		iright[block[i]] = max(i, iright[block[i]]);
	}
}

void add(int l, int r, int d) {
	if (block[l] == block[r]) {
		for (int i = ileft[block[l]]; i <= iright[block[l]]; ++i) {
			x[i] = (k[block[l]] * x[i] + b[block[l]]) % Inf;
		}
		k[block[l]] = 1;
		b[block[l]] = 0;
		for (int i = l; i <= r; ++i) {
			x[i] = (x[i] + d) % Inf;
		}
	} else {
		add(l, iright[block[l]], d);
		add(ileft[block[r]], r, d);
		for (int j = block[l] + 1; j <= block[r] - 1; ++j) {
			b[j] = (b[j] + d) % Inf;
		}
	}
}

void mul(int l, int r, int d) {
	if (block[l] == block[r]) {
		for (int i = ileft[block[l]]; i <= iright[block[l]]; ++i) {
			x[i] = (k[block[l]] * x[i] + b[block[l]]) % Inf;
		}
		k[block[l]] = 1;
		b[block[l]] = 0;
		for (int i = l; i <= r; ++i) {
			x[i] = (x[i] * d) % Inf;
		}
	} else {
		mul(l, iright[block[l]], d);
		mul(ileft[block[r]], r, d);
		for (int j = block[l] + 1; j <= block[r] - 1; ++j) {
			k[j] = (k[j] * d) % Inf;
			b[j] = (b[j] * d) % Inf;
		}
	}
}

int main() {
	int n, m;
	size_t l, r, p;
	long long d;
	char c;

	cin >> n;
	x.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	init(n);

	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> c;
		if (c == '?') {
			cin >> p;
			cout << (k[block[p]] * x[p] + b[block[p]]) % Inf << "\n";
		} else if (c == '+') {
			cin >> l >> r >> d;
			add(l, r, d);
		} else {
			cin >> l >> r >> d;
			mul(l, r, d);
		}
	}

	return 0;
}