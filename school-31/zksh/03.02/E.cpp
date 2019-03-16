#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

struct impr {
	int type;
	int pos;
	unsigned long long delt;
	int ind;
	impr(int param1 = 0, int param2 = 0, unsigned long long param3 = 0, int param4 = 0) {
		type = param1;
		pos = param2;
		delt = param3;
		ind = param4;
	}
};

bool types[4];
vector<unsigned long long> a, a_copy;
vector<int> best, cur, ans;
vector<impr> one, two, thr, all, good;
unsigned long long most, ksi;

bool comp_mul(impr x, impr y) {
	return (x.delt > y.delt);
}

bool comp_upd(impr x, impr y) {
	return (x.delt * a[y.pos] > y.delt * a[x.pos]);
}

void gen(int k, int n, int m, int cnt, int s) {
//	cout << k << " " << n << " " << m << " " << cnt << " " << s << "\n";
	a_copy = a;
	for (int i = 0; i < (int)cur.size(); ++i) {
	//	cout << cur[i];
		if (all[cur[i]].type == 1) {
		//	cout << "-1 ";
			a_copy[all[cur[i]].pos] = all[cur[i]].delt;
		} else if (all[cur[i]].type == 2) {
		//	cout << "-2 ";
			a_copy[all[cur[i]].pos] += all[cur[i]].delt;
		} else if (all[cur[i]].type == 3) {
		//	cout << "-3 ";
			a_copy[all[cur[i]].pos] *= all[cur[i]].delt;
		}
	}
//	cout << "\n";
	ksi = 1;
	for (int i = 0; i < k; ++i) {
	//	cout << a_copy[i] << " ";
		ksi *= a_copy[i];
	}
//	cout << "\n" << ksi << "\n";
	if (ksi > most) {
		ans = cur;
		most = ksi;
	}
	if (cnt >= m) {
		return;
	}
	for (int i = s + 1; i < n; ++i) {
		cur.push_back(i);
		gen(k, n, m, cnt + 1, i);
		cur.pop_back();
	}
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int k, n, m, l;
	int t, c;
	unsigned long long b;
	cin >> k >> n >> m;
	a.resize(k);
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> t >> c >> b;
		if (t == 1) {
			one.push_back(impr(t, c - 1, b, i + 1));
		} else if (t == 2) {
			two.push_back(impr(t, c - 1, b, i + 1));
		} else {
			thr.push_back(impr(t, c - 1, b, i + 1));
		}
		all.push_back(impr(t, c - 1, b, i + 1));
		types[t] = true;
	}
	if (types[3] && !types[2] && !types[1]) {
	//	cout << "Presentation Error\n";
		sort(thr.begin(), thr.end(), comp_mul);
	//	for (int i = 0; i < thr.size(); ++i) {
	//		cout << thr[i].delt << "\n";
	//	}
		l = m;
		cout << l << "\n";
		for (int i = 0; i < l; ++i) {
			cout << thr[i].ind << " \n"[i == l - 1];
		}
	} else if (types[1] && !types[2] && !types[3]) {
		best.assign(k, -1);
		for (int i = 0; i < n; ++i) {
			int j = one[i].pos;
			int new_value = one[i].delt;
		//	cout << "ok\n";
		//	cout << j << " " << best[j] << " " << a[j] << "\n";
			int old_value = best[j] == -1 ? a[j] : one[best[j]].delt;
		//	cout << ".ok\n";
			if (new_value > old_value) {
				best[j] = i;
			}
		}
		for (int i = 0; i < k; ++i) {
			if (best[i] != -1) {
				good.push_back(one[best[i]]);
			}
		}
		sort(good.begin(), good.end(), comp_upd);
		l = min((int)good.size(), m);
		cout << l << "\n";
		for (int i = 0; i < l; ++i) {
			cout << good[i].ind << " \n"[i == l - 1];
		}
	} else if (n <= 10) {
		int cnt = 0;
		int s = -1;
		most = 0;
		gen(k, n, m, cnt, s);
		l = (int)ans.size();
		cout << l << "\n";
		for (int i = 0; i < l; ++i) {
			cout << ans[i] + 1 << " \n"[i == l - 1];
		}
	} else {
		cout << "Presentation error\n";
	}
	return 0;
}