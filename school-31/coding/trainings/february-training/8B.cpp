#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

vector<int> a, b;

void shift(int l, int r) {
    int v = b[l];
    for (int i = l; i < r; ++i) {
        b[i] = b[i + 1];
    }
    b[r] = v;
}

void dummy(int n) {
    b.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        b[i] = i;
	}

    for (int k = 2; k <= n; ++k) {
        for (int i = 1; i <= n; i += k) {
            shift(i, min(n, i + k - 1));
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << b[i] << " \n"[i == n];
    }
}

int main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif

	int n;

	cin >> n;

	a.assign(2 * n + 1, 0);
	b.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		a[i] = i;
		b[i] = i;
	}

	for (int k = 2; k <= n; ++k) {
		int r = k - 1 + n;
		if (n % k == 0) {
			r -= k;
		} else {
			r -= n % k;
		}
		a[n + k - 1] = a[r];
		for (int i = r; i - k >= k - 1; i -= k) {
			a[i] = a[i - k];
		}
	}

	for (int i = n; i <= 2 * n - 1; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;
}