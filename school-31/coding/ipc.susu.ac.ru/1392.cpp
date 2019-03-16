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

string nums[100];
vector<string> a;
vector<string> b;
vector<bool> used;
int mt[100];

string get(int n) {
	string res = "";
	for (int i = 0; i < 2; ++i) {
		res = (char)(n % 10 + '0') + res;
		n /= 10;
	}
	return res;
}

bool valid(string s1, string s2) {
	if (s1[0] != s2[0] && s1[0] != '*' && s2[0] != '*') {
		return false;
	}
	if (s1[1] != s2[1] && s1[1] != '*' && s2[1] != '*') {
		return false;
	}
	return true;
}

bool kuhn(int v, int n) {
	if (used[v]) {
		return false;
	}
	used[v] = true;
	for (int j = 1; j <= n - 1; ++j) {
		string to = a[j];
		if (!valid(num[v], to)) {
			continue;
		}
		if (mt[to] == None || kuhn(, n)) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif // DEBUG
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, nmin, nmax, sz;
	for (int i = 0; i < 100; ++i) {
		nums[i] = get(i);
		mt[i] = None;
	}
	string a;
	cin >> n;
	a.resize(n);
	for (int i = 1; i <= n - 1; ++i) {
		cin >> a[i];
	}
	nmax = 0;
	nmin = 100;
	for (int k = 1; k <= n; ++k) {
		b.clear();
		b.push_back(0);
		for (int m = 1; m <= n; ++m) {
			if (m == k) {
				continue;
			}
			b.push_back(m);
		}
		mt.assign(n + 1, None);
		sz = 0;
		for (int v = 1; v <= n - 1; ++v) {
			used.assign(n + 1, false);
			if (kuhn(v, n)) {
				++sz;
			}
		}
		if (sz == n - 1) {
			nmin = min(k, nmin);
			nmax = max(k, nmax);
		}
	}
	cout << nmin << " " << nmax << "\n";

	return 0;
}