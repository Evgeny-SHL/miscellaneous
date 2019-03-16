#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b;

int main() {
	int n;
	bool p = true;

	cin >> n;
	a.resize(n);
	b.resize(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < n; ++i) {
		bool f = true;
		for (int j = 0; j < n; ++j)
			if (a[i] == b[j]) {
				f = false;
				break;
			}
		if (f) {
			p = false;
			cout << a[i] << " ";
		}
	}

	if (p) cout << -1;

	return 0;
}