#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	freopen("p.txt", "r", stdin);
	freopen("list.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int p, k;
	cout << "{\n\t";
	k = 0;
	do {
		cin >> p;
		if (p < 1e7) {
			++k;
			cout << p << ",";
			if (k == 6) {
				cout << "\n\t";
				k = 0;
			} else {
				cout << " ";
			}
		} else {
			break;
		}
	} while (true);
	if (k != 0) {
		cout << "\n}";
	}
	return 0;
}