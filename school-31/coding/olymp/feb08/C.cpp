#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

struct oper {
	int type;
	int a, b;
	oper(int p1, int p1, int t) {
		a = p1;
		b = p2;
		type = t;
	}
};

set<int> cur, mem, need;
vector<int> a;
vector<int> cnt;
vector<oper> ans;

void gen(int t, set<int> memory, vector<oper> ans) {
	set<int> curm = memory;
	vector<oper> curo = cur;
	for (int a = 0; a <= 42; ++a) {
		if (memory.find(a) != memory.end()) {
			for (int b = 0; b <= 42; ++b) {
				if (memory.find(b) != memory.end()) {
					curm.insert(a + b);
					curo[t] = oper(a, b, t);
					gen(t + 1, curm, curo);
					curm.erase(a + b);
				}
			}
		}
	}
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n;
	int k;

	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		need.insert(a[i]);
	}
	cnt.resize(43, 50);
	cnt[1] = 0;
	mem.insert(1);
	gen(1, mem, cnt);
	for (int t = 1; t <= 42; ++t) {
		cur.clear();
		for (int a = 0; a <= 42; ++a) {
			if (mem.find(a) == mem.end()) {
				continue;
			}
			for (int b = 0; b <= 42; ++b) {
				if (mem.find(b) != mem.end()) {
					if (a == 1 && b == 2)
					if (a + b <= 42) {
						cur.insert(a + b);
					}
					cur.insert(abs(a - b));
				}

			}
			for (int k = 0; k <= 5; ++k) {
				if (a << k <= 42) {
					cur.insert(a << k);
				}
			}
		}
		for (set<int>::iterator it = cur.begin(); it != cur.end(); ++it) {
			if (*it <= 42) {
				cnt[*it] = min(t, cnt[*it]);
			}
		}
		mem.insert(cur.begin(), cur.end());
	}

	for (int i = 0; i <= 42; ++i) {
		cout << i << " " << cnt[i] << "\n";
	}

	return 0;
}

