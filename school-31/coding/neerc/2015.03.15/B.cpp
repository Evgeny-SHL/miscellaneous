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

struct event {
	int tm, tp, dlt, ind;
	event(int p1 = 0, int p2 = 0, int p3 = 0, int p4 = 0) {
		tm = p1;
		tp = p2;
		dlt = p3;
		ind = p4;
	}
};

bool comp(event a, event b) {
	return (a.tm < b.tm || a.tm == b.tm && a.tp < b.tp);
}

vector<event> tms;
vector<bool> used;

int main() {
	freopen("bestbuy.in", "r", stdin);
	freopen("bestbuy.out", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int c1, c2, n, m, k, c, t, l, r, cur, ans;
	cin >> c1 >> c2;
	cin >> n;
	tms.push_back(event());
	for (int i = 1; i <= n; ++i) {
		cin >> c >> t;
		tms.push_back(event(t, 1, c));
	}
	cin >> m;
	used.resize(m + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> l >> r;
		tms.push_back(event(l, 2, c1, i));
		tms.push_back(event(r, 3, c2, i));
		used[i] = false;
	}
	sort(tms.begin() + 1, tms.end(), comp);
	ans = 0;
	cur = 0;
	k = (int)tms.size() - 1;
	for (int i = 1; i <= k; ++i) {
	//	cout << tms[i].tm << ": ";
		if (tms[i].tp == 1) {
		//	cout << "get " << tms[i].dlt << "\n";
			cur += tms[i].dlt;
		} else if (tms[i].tp == 2) {
			if (tms[i].dlt <= cur) {
			//	cout << "buy internet " << tms[i].ind << "\n";
				cur -= tms[i].dlt;
				used[tms[i].ind] = true;
				++ans;
			} else {
			//	cout << "to order " << tms[i].ind << "\n";
			}
		} else {
			if (tms[i].dlt <= cur && !used[tms[i].ind]) {
			//	cout << "buy courier " << tms[i].ind << "\n";
				cur -= tms[i].dlt;
				used[tms[i].ind] = true;
				++ans;
			} else if (!used[tms[i].ind]) {
			//	cout << "sadly, sadly " << tms[i].ind << "\n";
			} else {
			//	cout << "already ok " << tms[i].ind << "\n";
			}
		}
	}
	cout << ans << "\n";

	return 0;
}