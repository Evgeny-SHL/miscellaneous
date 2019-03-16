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

vector<int> cnt;

int main() {
	freopen("apparel.in", "r", stdin);
	freopen("apparel.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int c = 0; c < t; ++c) {
		cnt.assign(101, 0);
		int n, x;
		int m = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			++cnt[x];
			if (cnt[x] > cnt[m]) {
				m = x;
			}
		}
		int k = 0;
		for (int i = 1; i <= 100; ++i) {
			k += (cnt[i] == cnt[m]);
		}
		if (k > 1) {
			cout << "0\n";
		} else {
			cout << m << "\n";
		}
	}

	return 0;
}
