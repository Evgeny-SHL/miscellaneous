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

struct task {
	long long a, b;
	int ind;
	task(long long param1 = 0, long long param2 = 0, int param3 = 0) {
		a = param1;
		b = param2;
		ind = param3;
	}
};

vector<long long> end1, end2;
vector<task> t;

bool comparator(task x, task y) {
	return (-min(x.a, y.b) > -min(x.b, y.a));
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	t.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i].a;
	}
	for (int i = 0; i < n; ++i) {
		cin >> t[i].b;
		t[i].ind = i + 1;
	}
	sort(t.begin(), t.end(), comparator);
	end1.resize(n);
	end2.resize(n);
	end1[0] = t[0].a;
	end2[0] = end1[0] + t[0].b;
	for (int i = 1; i < n; ++i) {
		end1[i] = end1[i - 1] + t[i].a;
		end2[i] = max(end1[i], end2[i - 1]) + t[i].b;
	}
	cout << end2[n - 1] << "\n";
	for (int i = 0; i < n; ++i) {
		cout << t[i].ind << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		cout << t[i].ind << " ";
	}
	cout << "\n";
	return 0;
}