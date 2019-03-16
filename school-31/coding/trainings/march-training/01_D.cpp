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
const long long sInf = (long long)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);

const int Max = 24;

#define my_it set< vector<bool> >::iterator

set< vector<bool> > mb, dlg;
vector<bool> cur;
vector<bool> ok;

void srh(int s, int n, int k, int t) {
	if (k > 0) {
		for (int i = s; i <= n - t; ++i) {
			if (i == 0 || !cur[i - 1]) {
				for (int j = i; j < i + t; ++j) {
					cur[j] = true;
				}
				srh(i + t + 1, n, k - 1, t);
				for (int j = i; j < i + t; ++j) {
					cur[j] = false;
				}
			}
		}
	} else {
		mb.insert(cur);
	}
}

int count_ok(int n) {
	int cnt;
	ok.assign(n, true);
	for (my_it it = mb.begin(); it != mb.end(); ++it) {
		for (int i = 0; i < n; ++i) {
			ok[i] = ok[i] && (*it)[i];
		}
	}
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt = cnt + (int)ok[i];
	}
	return cnt;
}

int main() {
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, t, k, cnt, c;

	cin >> n >> t >> k;
	assert(n <= 1000);
	cur.resize(n);
	srh(0, n, t, k);

	cout << count_ok(n) << "\n";
//	cout << count_ok(n);
	cout.flush();

	while (true) {
		cin >> c;
		--c;
		if (ok[c]) {
			cout << 1 << "\n";
		//	cout << 1;
			cout.flush();
			break;
		} else {
			cout << 0 << " ";
			dlg.clear();
			for (my_it it = mb.begin(); it != mb.end(); ++it) {
				if ((*it)[c]) {
					dlg.insert(*it);
				}
			}
			for (my_it it = dlg.begin(); it != dlg.end(); ++it) {
				mb.erase(*it);
			}
			cout << count_ok(n) << "\n";
		//	cout << count_ok(n);
			cout.flush();
		}
	}

	return 0;
}
