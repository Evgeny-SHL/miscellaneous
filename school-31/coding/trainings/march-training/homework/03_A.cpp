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

int main() {
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	string s;
	int n;
	vector<int> p;

	cin >> s;
	n = (int)s.length();
	p.resize(n);
	p[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		p[i] = j;
	}
	for (int i = 0; i < n; ++i) {
		cout << p[i] << " ";
	}
	cout << "\n";

	return 0;
}
