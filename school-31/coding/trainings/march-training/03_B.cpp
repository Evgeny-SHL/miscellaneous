#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

const double Eps = 1e-9;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;
const int Max = 10000;

string freq[Max + 1];
//int freq[Max + 1];
//int cnt[Max + 1];
unordered_map<string, int> cnt;
int ans[Max + 1];
string nums[Max + 1];

/*void print(int n) {
	for (int t = 1; t <= n; ++t) {
		cerr << ans[t] << " ";
	}
	cerr << "\n";
	cerr << "\n";
	for (int t = 1; t <= n; ++t) {
		cerr << freq[t] << " ";
	}
	cerr << "\n";
	for (int t = 0; t <= n; ++t) {
		cerr << cnt[t] << " ";
	}
	cerr << "\n";
	cerr << "\n";
}*/

string to_string(int x) {
	string res = ".";
	do {
		res = (char)(x % 10) + res;
		x /= 10;
	} while (x > 0);
	return res;
}

int main() {
	freopen("theatre.in", "r", stdin);
	freopen("theatre.out", "w", stdout);
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	for (int i = 0; i <= Max; ++i) {
		freq[i] = "";
		ans[i] = 0;
		nums[i] = to_string(i);
	}

	int n, m, k, act;

	cin >> n >> m;
	cnt[""] = n;
	for (int i = 1; i <= m; ++i) {
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> act;
			if (ans[act] == 0) {
				--cnt[freq[act]];
				freq[act] += nums[i];
				++cnt[freq[act]];
			}
		}
		for (int p = 1; p <= n; ++p) {
			if (ans[p] == 0 && cnt[freq[p]] == 1) {
				ans[p] = i;
				cnt[freq[p]] = 0;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}
