#include <iostream>;
using namespace std;

int main() {
	int n, a[999], x, k = 0;

	cin >> n;
	for (int i = 0; i < n;)
		cin >> a[i++];

	cin >> x;
	for (int i = 0; i < n;)
		if (a[i++] == x) k++;

	cout << k;

	return 0;
}