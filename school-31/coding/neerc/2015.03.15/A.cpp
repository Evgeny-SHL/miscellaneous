#pragma comment(linker, "/STACK:268435456")
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;

const double Eps = (double)(1.0e-9);
const long long bInf = (long long)(1e18 + 3);
const int sInf = (int)(1e9 + 7);
const int None = -1;
const double Pi = acos(-1.0);
const double Eu = exp(1.0);

map<int, int> clr;

int main() {
	freopen("colors.in", "r", stdin);
	freopen("colors.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, k, c;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> c;
		clr[c]++;
	}
	while (k > 0) {
		for (auto it = clr.begin(); (k > 0) && (it != clr.end()); ++it) {
			if (it->second > 0) {
				cout << it->first << " \n"[k == 1];
				--it->second;
				--k;
			}
		}
	}

	return 0;
}