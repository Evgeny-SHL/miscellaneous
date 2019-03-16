#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

const int MAX_N = 100000;
const int K = 3;
const long long MOD[K] = {
	982451653, 1000000007, 1000000009
};
const long long HASH_CONST[K] = {
	7, 11, 13
};
long long DEG_CONST[K][MAX_N];
long long HASH[K][MAX_N];

void init(string s, int n) {
	for (int h = 0; h < K; ++h) {
		DEG_CONST[h][0] = 1;
		for (int i = 1; i < n; ++i) {
			DEG_CONST[h][i] = (HASH_CONST[h] * DEG_CONST[h][i - 1]) % MOD[h];
		}
	}
	for (int h = 0; h < K; ++h) {
		HASH[h][0] = (s[0] - 'a' + 1);
	}
	for (int h = 0; h < K; ++h) {
		for (int i = 1; i < n; ++i) {
			HASH[h][i] = (HASH[h][i - 1] + (s[i] - 'a' + 1) * DEG_CONST[h][i]) % MOD[h];
		}
	}
}

bool is_good(string s, int i, int j, int m) {
	long long h1 = 0;
	long long h2 = 0;
	for (int h = 0; h < K; ++h) {
		if (i > 0) {
			h1 = (HASH[h][i + m - 1] - HASH[h][i - 1] + MOD[h]) % MOD[h];
		} else {
			h1 = HASH[h][i + m - 1];
		}
		if (j > 0) {
			h2 = (HASH[h][j + m - 1] - HASH[h][j - 1] + MOD[h]) % MOD[h];
		} else {
			h2 = HASH[h][j + m - 1];
		}
		if ((h1 * DEG_CONST[h][j - i]) % MOD[h] != h2) {
			return false;
		}
	}
	return true;
}

int main() {
	string s;
	int n, q, i, j, l, r, m;

	fin >> s;
	n = s.length();
	init(s, n);
	fin >> q;

	for (int t = 0; t < q; ++t) {
		fin >> i >> j;
		--i;
		--j;
		if (i > j) {
			swap(i, j);
		}
		l = 0;
		r = n - j + 1;
		while (r - l > 1) {
			m = (l + r) / 2;
			if (is_good(s, i, j, m)) {
				l = m;
			} else {
				r = m;
			}
		}
		fout << l << '\n';
	}

	return 0;
}