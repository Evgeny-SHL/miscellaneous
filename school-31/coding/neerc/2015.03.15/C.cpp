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
const int Max = 1e7;
const int Amt = 664579;

vector<int> prime;
vector< vector<int> > a;
map<int, long long> alh;

void gen_primes(int k) {
	prime.push_back(2);
	prime.push_back(3);
	int len = (int)prime.size();
	bool good;
	int p = prime[len - 1];
	while (len < k) {
		p += 2;
		if (p > Max) {
			return;
		}
		good = true;
		for (int i = 0; i < len; ++i) {
			if (p % prime[i] == 0) {
				good = false;
				break;
			}
		}
		if (good) {
			prime.push_back(p);
			++len;
		}
	}
}

bool check(int n) {
	int cnt, deg;
	alh.clear();
	for (int i = 1; i <= n; ++i) {
		alh[a[i][1]]++;
	}
	cnt = 1;
	for (auto it = alh.begin(); it != alh.end(); ++it) {
		cnt = (cnt * (it->second + 1)) % sInf;
	}
	for (int j = 2; j <= n; ++j) {
		alh.clear();
		for (int i = 1; i <= n; ++i) {
			alh[a[i][j]]++;
		}
		deg = 1;
		for (auto it = alh.begin(); it != alh.end(); ++it) {
			deg = (deg * (it->second + 1)) % sInf;
		}
		if (deg != cnt) {
			return false;
		}
	}
	for (int i = 1; i <= n; ++i) {
		alh.clear();
		for (int j = 1; j <= n; ++j) {
			alh[a[i][j]]++;
		}
		deg = 1;
		for (auto it = alh.begin(); it != alh.end(); ++it) {
			deg = (deg * (it->second + 1)) % sInf;
		}
		if (deg != cnt) {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("parade.in", "r", stdin);
	freopen("parade.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int k, n, p, t;
	long long cnt, deg;
	cin >> k >> n;
	if (k > n * n || k > Amt) {
		cout << -1 << "\n";
	} else {
		gen_primes(k);
		if (n % k != 0) {
			p = 0;
			a.resize(n + 1);
			for (int i = 1; i <= n; ++i) {
				a[i].resize(n + 1);
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					a[i][j] = prime[p];
					++p;
					if (p == k) {
						p = 0;
					}
				}
			}
			if (check(n)) {
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= n; ++j) {
						cout << a[i][j] << " \n"[j == n];
					}
				}
			} else {
				cout << -1 << "\n";
			}
		} else {
			p = 0;
			a.resize(n + 1);
			for (int i = 1; i <= n; ++i) {
				a[i].resize(n + 1);
			}
			for (int j = 1; j <= n; ++j) {
				a[1][j] = prime[p];
				++p;
				if (p == k) {
					p = 0;
				}
			}
			for (int i = 2; i <= n; ++i) {
				a[i][1] = a[i - 1][n];
				for (int j = 2; j <= n; ++j) {
					a[i][j] = a[i - 1][j - 1];
				}
			}
			if (check(n)) {
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= n; ++j) {
						cout << a[i][j] << " \n"[j == n];
					}
				}
			} else {
				cout << -1 << "\n";
			}
		}
	}

	return 0;
}