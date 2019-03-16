#include <iostream>;
using namespace std;

int main() {
	int n, a[999], x, f = false;

	cin >> n;
	for (int i = 0; i < n;)
		cin >> a[i++];

	cin >> x;
	for (int i = 0; i < n;)
		if (a[i++] == x) f = true;

	if (f) cout << "YES";
		else cout << "NO";

	return 0;
}