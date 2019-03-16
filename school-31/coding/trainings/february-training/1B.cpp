#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct psch {
	int key, val, nxt, prv;
	psch(int param1 = 0, int param2 = 0, int param3 = 0, int param4 = 0) {
		key = param1;
		val = param2;
		nxt = param3;
		prv = param4;
	}
};

vector<psch> p;

struct event {
	int a, b;
	event (int param1, int param2) {
		a = param1;
		b = param2;
		p[a].nxt = b;
		p[a].prv = a - 1;
		p[b].prv = a;
		p[b].nxt = b + 1;
	}
};

vector<event> ePast, ePres;

int main() {
	int n, m;
	int a;
	int ans;

	cin >> n;

	p.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		p.push_back(psch(a, i));
		if (i > 1 && p[i].key < p[i - 1].key) {
			ePast.push_back(event(i - 1, i));
		}
	}

	while (!ePast.empty()) {
		++ans;
		m = (int)ePast.size();
		for (int i = 0; i < m; ++i) {
			if (i > 0 && ePast[i - 1].b != ePast[i].a) {
				ePres.push_back(event(ePast[i - 1].b, ePast[i].a));
			}
		}
		ePast = ePres;
	}

	return 0;
}