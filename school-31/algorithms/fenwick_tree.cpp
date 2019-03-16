#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> data;

int next(int i) {
	return i | (i + 1);
}

int prev(int i) {
	return (i & (i + 1)) - 1;
}

void update(int pos, int v) {
	for (int i = pos; i < arr.size(); i = next(i))
		data[i] += v;
}

int cum_sum(int pos) {
	int res = 0;
	for (int i = pos; i >= 0; i = prev(i))
		res += data[i];
	return res;
}

int rsq(int l, int r) {
	return cum_sum(r) - cum_sum(l - 1);
}

void init() {
	int n = arr.size();
	data.resize(n, 0);
	for (int i = 0; i < n; ++i)
		update(i, arr[i]);
}

int main() {
	int n, m, l, r;

	cin >> n;
	arr.resize(n);
	data.resize(4 * n + 1);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> m;

	init();
	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		int s = rsq(l - 1, r - 1);
		cout << s << '\n';
	}

	return 0;
}