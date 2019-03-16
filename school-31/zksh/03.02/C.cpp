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

vector<int> a;

int main() {
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int n;
	long long k;
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < k; ++i) {
		bool f = true;
		for (int j = 0; j < n - 1; ++j) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				f = false;
				break;
			}
		}
		if (f) {
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}