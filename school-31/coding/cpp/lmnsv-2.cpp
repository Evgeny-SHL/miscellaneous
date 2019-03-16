#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int N = 819;
const int M = 3;
const int K = 250;
vector<int> a;
vector<string> b;

string rev_hex(int x) {
	string ans = "";
	for (int i = 0; i < M; ++i) {
		if (x % 16 < 10) {
			ans = ans + char('0' + x % 16);
		} else {
			ans = ans + char('A' + x % 16 - 10);
		}
		x /= 16;
	}
	return ans;
}

int rev_dec(string s) {
	int ans = 0;
	int p[M] = {1, 16, 256};
	for (int i = 0; i < M; ++i) {
        if (s[i] >= 'A' && s[i] <= 'F') {
			ans += p[i] * int(s[i] - 'A' + 10);
        } else {
			ans += p[i] * int(s[i] - '0');
        }
	}
	return ans;
}

bool comp(string a, string b) {
	return a > b;
}

int main() {
	a.resize(N);
	for (int i = 0; i < N; ++i) {
		a[i] = 5 * (i + 1);
	}
	b.resize(N);
	for (int j = 0; j < N; ++j) {
		b[j] = rev_hex(a[j]);
	}
	sort(b.begin(), b.end(), comp);
	for (int i = 0; i < N; ++i) {
		a[i] = rev_dec(b[i]);
	}
	cout << a[K - 1] << '\n';
	return 0;
}