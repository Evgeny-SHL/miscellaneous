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
const long long Inf = (long long)(1e18);
const int None = (int)(1e9 + 7);
const double Pi = acos(-1.0);
const double Eu = exp(1.0);


int main() {
	srand(time(NULL));
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	cout << fixed;
	cout.precision(9);
	long long n;
	int k;
	cin >> n >> k;
	long long ans = Inf;
//	cout << pow(n, 1.0 / (k - 1)) << "\n";
	if (k == 1) {
		ans = (n + 1) / 2;
	} else {
		for (long long d = 1; d <= (long long)(pow(n, 1.0 / (k - 1)) + 1); ++d) {
			long long dk = 1;
			if (n % d != 0) {
				continue;
			}
			for (int j = 1; j < k; ++j) {
				dk *= d;
			}
			if (n % dk == 0) {
				long long leaf = (n / dk + 1) / 2;
				long long nodes = 1;
				for (int j = 1; j < k; ++j) {
					nodes *= (d + 1) / 2;
				}
			//	cout << d << "\n";
			//	cout << leaf << " " << nodes << "\n";
				ans = min(ans, nodes * leaf);
			//	cout << nodes * leaf << "\n";
			//	cout << "\n";
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
