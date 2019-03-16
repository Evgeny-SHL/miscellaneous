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

string seq;
vector< vector< vector< pair<int, int> > > > dp;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif // DEBUG
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int t, n;
	cin >> t;
	for (int c = 1; c <= t; ++c) {
		cin >> seq;
		n = (int)seq.lentgh();
		seq = '*' + seq;
        dp.clear();
        dp.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
			dp[i].resize(2);
			dp[i][0].resize(2);
			dp[i][1].resize(2);
        }

	}

	return 0;
}