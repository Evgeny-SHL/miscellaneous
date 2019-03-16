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
using namespace std;

const int Max = (int)1e5;

int n, k;
string s;
map<long long, int> box;

long long h[Max];
long long deg[Max];
long long Const[1] = { 19 };
long long Inf[1] = { 1e9 + 9 };

void init() {
	deg[0] = 1;
	h[0] = (deg[0] * (int)(s[0] - 'a' + 1)) % Inf[0];
//	cout << h[0] << " ";
	for (int i = 1; i < n; ++i) {
		deg[i] = (deg[i - 1] * Const[0]) % Inf[0];
		h[i] = (h[i - 1] + (deg[i] * (s[i] - 'a' + 1)) % Inf[0]) % Inf[0];
	//	cout << h[i] << " ";
	}
//	cout << "\n";
}

int cnt(int len) {
	box.clear();
	int freq;
	int l;
	long long curh = (h[len - 1] * deg[n - 1]) % Inf[0];
	box[curh] = 1;
	freq = 1;
	l = 1;
//	cout << "**** " << len << "\n";
//	cout << curh << "\n";
	for (int i = 1; i <= n - len; ++i) {
		curh = (deg[n - 1 - i] * ((h[i + len - 1] - h[i - 1] + Inf[0]) % Inf[0])) % Inf[0];
	//	cout << i << " " << i + len - 1 << "\n";
	//	cout << curh << "\n";
		if (box.find(curh) == box.end()) {
			box[curh] = 1;
		} else {
			++box[curh];
		}
		if (box[curh] > freq) {
			l = i;
			freq = box[curh];
		}
	}
//	cout << len << " " << freq << "\n";
	return freq;
}

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "r", stdout);
#endif
	cin >> n >> k;
	cin >> s;
	init();
	int l = 0;
	int r = n + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (cnt(m) >= k) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << l << "\n";
	return 0;
}