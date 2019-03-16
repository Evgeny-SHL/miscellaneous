#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > f;

vector<int> sum(vector<int> a, vector<int> b) {
	vector<int> ans;
	ans.resize(101, 0);
	ans[0] = a[0] + b[0];
	for (int i = 1; i < 101; ++i) {
		ans[i] = ans[i - 1] / 10 + a[i] + b[i];
		ans[i - 1] %= 10;

	}
	ans[100] %= 10;
	return ans;
}

int main() {
	int n;
	cin >> n;
	f.resize(n + 1);
	for (int i = 0; i <= n; ++i) {
		f[i].resize(101, 0);
	}
	f[0][0] = 1;
	f[1][0] = 2;
	for (int i = 2; i <= n; ++i) {
		f[i] = sum(f[i - 1], f[i - 2]);
	}
	int l = 100;
	while (f[n][l] == 0) {
		--l;
	}
	for (int i = l; i >= 0; --i) {
		cout << f[n][i];
	}
	cout << '\n';
	return 0;
}