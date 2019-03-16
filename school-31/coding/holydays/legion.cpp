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

map<long long, long long> cash;

long long cnt(long long n) {
	if (cash.find(n) != cash.end()) {
		return cash[n];
	}
	if (n == 3) {
		return 1;
	}
	if (n < 3) {
		return 0;
	}
	if (n % 2 == 0) {
		cash[n] = 2 * cnt(n / 2);
		return cash[n];
	}
	cash[n] = cnt(n / 2) + cnt((n + 1) / 2);
	return cash[n];
}

int main() {
	freopen("legion.in", "r", stdin);
	freopen("legion.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int c = 0; c < t; ++c) {
		long long n;
		cin >> n;
		cout << cnt(n) << "\n";
	}

	return 0;
}
