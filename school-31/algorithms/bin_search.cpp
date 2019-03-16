#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
const int NIL = -1;

int bin_search(int v, int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (v == a[mid])
			return mid;
		else if (v > a[mid])
			low = mid + 1;
		else high = mid - 1;
	}
	return NIL;
}

int rec_bin_search(int v, int low, int high) {
	if (low > high)
		return NIL;
	int mid = (low + high) / 2;
	if (v == a[mid])
		return mid;
	else if (v > a[mid])
		return rec_bin_search(v, mid + 1, high);
	else return rec_bin_search(v, low, mid - 1);
}

int main() {
	int n, x;

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	cin >> x;

	cout << bin_search(x, 0, n - 1);

	return 0;
}