#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <cmath>
#include <random>
#include <ctime>
#include <cassert>
using namespace std;

const double Eps = (double)(1e-9);
const int Inf = (int)(1e9 + 7);
const int None = -1;
const double Pi = acos(-1.0);
const double Eu = exp(1.0);

vector<int> h, inv;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(0);
	cout << fixed;
	cout.precision(9);

	int n;
	cin >> n;
	h.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	inv.resize(n + 1);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i - 1; ++j) {
			if (h[j] > h[i]) {
				++inv[i];
			}
		}
		sum += inv[i];
	}
	if (sum == 0) {
		cout << -1 << " " << -1 << "\n";
		return 0;
	}
	int x = 1, y = 2, ans = Inf;
	for (int a = 1; a <= n - 1; ++a) {
		for (int b = a + 1; b <= n; ++b) {
			int delt = 0;
			for (int c = a; c <= b; ++c) {
				if (h[c] < h[a]) {
					delt--;
				}
				if (h[c] < h[b]) {
					delt++;
				}
			}
			if (delt < ans) {
				x = a;
				y = b;
				ans = delt;
			}
		}
	}
	cout << x << " " << y << "\n";
	return 0;
}
