#include <vector>
#include <iostream>
using namespace std;

vector<long long> f;
const long long INF = 100000000000000000LL;


int main() {
	int n;
	cin >> n;
	f.resize(n + 1, 0);
	f[1] = 0;
	for (int i = 2; i <= n; ++i) {
		int a, b, c;
		a = b = c = INF;
		a = f[i - 1] + 1;
		if (i % 2 == 0) {
			b = f[i / 2] + 1;
		}
		if (i % 3 == 0) {
			c = f[i / 3] + 1;
		}
		f[i] = min(a, min(b, c));
	}
	cout << f[n] << '\n';
}