#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:16777216")

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const long long bInf = (long long)(1e18 + 3);
const int sInf = (int)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector< vector<bool> > bad;
vector< vector<int> > fld;

int main() {
	freopen("minesweeper.in", "r", stdin);
	freopen("minesweeper.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m;
	char c;
	cin >> n >> m;
	fld.resize(n);
	bad.resize(n);
	for (int i = 0; i < n; ++i) {
		fld[i].resize(m);
		bad[i].assign(m, false);
		for (int j = 0; j < m; ++j) {
			cin >> c;
			if (c == '*') {
				fld[i][j] = -2;
			} else if (c == 'F') {
				fld[i][j] = -1;
			} else {
				fld[i][j] = (int)(c - '0');
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (fld[i][j] < 0) {
				continue;
			}
			int s = 0;
			for (int di = -1; di <= 1; ++di) {
				if ((i + di < 0) || (i + di >= n)) {
					continue;
				}
				for (int dj = -1; dj <= 1; ++dj) {
					if ((j + dj < 0) || (j + dj >= m)) {
						continue;
					}
					if (fld[i + di][j + dj] == -1) {
						++s;
					}
				}
			}
			if (s > fld[i][j]) {
				for (int di = -1; di <= 1; ++di) {
					if ((i + di < 0) || (i + di >= n)) {
						continue;
					}
					for (int dj = -1; dj <= 1; ++dj) {
						if ((j + dj < 0) || (j + dj >= m)) {
							continue;
						}
						if (fld[i + di][j + dj] == -1) {
							bad[i + di][j + dj] = true;
						}
					}
				}
			}
		}
	}
	int k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			k += (int)bad[i][j];
		}
	}
	cout << k << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (bad[i][j]) {
				cout << i + 1 << " " << j + 1 << "\n";
			}
		}
	}

	return 0;
}
