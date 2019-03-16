#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> cnt, b;

void write(int n) {
	for (int i = 0; i < 3 * n; ++i) {
		cout << b[i] << " ";
	}
	cout << '\n';
}

int main() {
	int n, l;

	cin >> n;

	cnt.resize(4);
	for (int i = 0; i < n; ++i) {
		cin >> l;
		cnt[l] += 1;
	}
	b.resize(3 * n);

	if (cnt[3] == 0 && cnt[2] > 0 && cnt[1] > 0) {
		cout << "NO\n";
		return 0;
	}

	int s = 1;
	while (cnt[1] > 0) {
		b[s] = 1;
		cnt[1] -= 1;
		s += 2;
	}

	//	write(n);

	if (cnt[3] > 0) {
		b[s - 1] = 3;
		cnt[3] -= 1;
	}

	//	write(n);

	while (cnt[2] > 0) {
		b[s] = 2;
		cnt[2] -= 1;
		s += 2;
	}
	int max = s;

	//	write(n);

	s = 0;
	while (cnt[3] > 0) {
		if (b[s] == 3) {
			s += 2;
		}
		b[s] = 3;
		cnt[3] -= 1;
		s += 2;
	}

	//	write(n);

	if (s - 2 < max) {
		cout << "YES\n";
		for (int i = 0; i < 3 * n; ++i) {
			if (b[i] > 0) {
				cout << b[i] << " ";
			}
		}
	} else {
		cout << "NO\n";
	}

	return 0;
}