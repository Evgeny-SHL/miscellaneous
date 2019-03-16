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

vector< vector<int> > plan;

int main() {
	freopen("hotel.in", "r", stdin);
	freopen("hotel.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	char c;
	plan.resize(n);
	for (int i = 0; i < n; ++i) {
		plan[i].resize(m);
		for (int j = 0; j < m; ++j) {
			cin >> c;
			if (c == '*') {
				plan[i][j] = 0;
			} else {
				plan[i][j] = 1;
			}
		}
	}
	int res = 0;
	for (int ru = 1; ru < n - 1; ++ru) {
		for (int cl = 1; cl < m - 1; ++cl) {
			for (int rd = ru; rd < n - 1; ++rd) {
				for (int cr = cl; cr < m - 1; ++cr) {
					int s0 = 1;
					for (int i = ru; (s0 > 0) && (i <= rd); ++i) {
						for (int j = cl; (s0 > 0) && (j <= cr); ++j) {
							if (plan[i][j] == 0) {
								s0 = 0;
							}
						}
					}
					if (s0 > 0) {
						res = max(res, (rd - ru + 1) * (cr - cl + 1));
					}
				}
			}
		}
	}
	cout << res << "\n";

	return 0;
}
