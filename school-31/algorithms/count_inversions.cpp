#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
vector<int> a_left;
vector<int> a_right;
const int INF = 1e9 + 7;

int merge_inversions(int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	a_left.resize(n1 + 2);
	a_right.resize(n2 + 2);
	for (int i = 1; i <= n1; ++i)
		a_left[i] = a[l + i - 1];
	for (int j = 1; j <= n2; ++j)
		a_right[j] = a[m + j];
	a_left[n1 + 1] = INF;
	a_right[n2 + 1] = INF;
	int i = 1;
	int j = 1;
	int inversions = 0;
	bool counted = false;
	for (int k = l; k <= r; ++k) {
		if (!counted && a_right[j] < a_left[i]) {
			inversions += n1 - i + 1;
			counted = true;
		}
		if (a_left[i] <= a_right[j]) {
			a[k] = a_left[i];
			++i;
		} else {
			a[k] = a_right[j];
			counted = false;
			++j;
		}
	}
	return inversions;
}

int count_inversions(int l, int r) {
	int inversions = 0;
	if (l < r) {
		int m = (l + r) / 2;
		inversions += count_inversions(l, m);
		inversions += count_inversions(m + 1, r);
		inversions += merge_inversions(l, m, r);
	}
	return inversions;
}

int main() {
	int n;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cout << count_inversions(0, n - 1) << '\n';

	return 0;
}