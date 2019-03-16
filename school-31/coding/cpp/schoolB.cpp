#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m = 1;

	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; ++i) {
		if (m < arr[i]) break;
		m = arr[i] + 1;
	}

	cout << m;

	return 0;
}