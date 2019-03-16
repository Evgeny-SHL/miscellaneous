#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

struct frnd {
	long long a, b;
	int ind, pos;
	frnd(long long param1 = 0, long long param2 = 0, int param3 = 0, int param4 = 0) {
		a = param1;
		b = param2;
		ind = param3;
		pos = param4;
	}
};

bool operator<(frnd x, frnd y) {
	return (x.b < y.b);
}

vector<int> ans;
vector<frnd> t_pl, t_mn, sadly;
multiset<frnd> bad;

bool comp_pl(frnd x, frnd y) {
	return (x.a < y.a ||
			x.a == y.a && x.b < y.b);
}

bool comp_mn(frnd x, frnd y) {
	return (x.a + x.b > y.a + y.b ||
			x.a + x.b == y.a + y.b && x.b > y.b);
}

bool comp_pos(frnd x, frnd y) {
	return (x.pos < y.pos);
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n;
	long long a0;
	int m, k;
	long long a, b;
	cin >> n >> a0;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (b >= 0) {
			t_pl.push_back(frnd(a, b, i + 1));
		} else {
			t_mn.push_back(frnd(a, b, i + 1));
		}
	}
	m = (int)t_pl.size();
	k = (int)t_mn.size();
	sort(t_pl.begin(), t_pl.end(), comp_pl);
	for (int i = 0; i < m; ++i) {
		if (t_pl[i].a > a0) {
			continue;
		} else {
			a0 += t_pl[i].b;
			ans.push_back(t_pl[i].ind);
		}
	}
	sort(t_mn.begin(), t_mn.end(), comp_mn);
	for (int i = 0; i < k; ++i) {
		t_mn[i].pos = i;
		if (t_mn[i].a <= a0) {
			bad.insert(t_mn[i]);
			a0 += t_mn[i].b;
		} else if (bad.size() > 0) {
			frnd worst = *bad.begin();
			if (t_mn[i].b >= worst.b && t_mn[i].a <= a0 - worst.b) {
				bad.erase(bad.begin());
				a0 -= worst.b;
				bad.insert(t_mn[i]);
				a0 += t_mn[i].b;
			}
		}
	}
	for (multiset<frnd>::iterator it = bad.begin(); it !=  bad.end(); ++it) {
		sadly.push_back(*it);
	}
	sort(sadly.begin(), sadly.end(), comp_pos);
	for (int i = 0; i < (int)sadly.size(); ++i) {
		ans.push_back(sadly[i].ind);
	}
	cout << (int)ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}