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

vector<vector<long long>> a;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(0));
	cout << fixed;
	cout.precision(2);
	ios_base::sync_with_stdio(0);

	long long n, m;
	cin >> n >> m;
	a.resize(n);
	for (long long i = 0; i < n; ++i) {
		a[i].resize(n);
		for (long long j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	long long r = 0;
	long long c = 0;
	long long sum = (long long)sInf;
	for (long long i = 0; i < n; ++i) {
		for (long long j = 0; j < n; ++j) {
			if (i + m >= n || j + m >= n) {
				continue;
			}
			long long h = sInf;
			for (long long p = i; p < i + m; ++p) {
				for (long long q = j; q < j + m; ++q) {
					h = min(h, a[p][q]);
				}
			}
			long long rep = 0;
			for (long long p = i; p < i + m; ++p) {
				for (long long q = j; q < j + m; ++q) {
					rep += abs(a[p][q] - h);
				}
			}
			if (rep < sum) {
				sum = rep;
				r = i;
				c = j;
			}
		}
	}
	cout << r << " " << c << "\n";

	return 0;
}
