#include <vector>
#include <iostream>
using namespace std;

vector<long long> f;
vector<string> pi;
const long long INF = 100000000000000000LL;

int main() {
	int n;
	cin >> n;
	f.resize(n + 1, 0);
	pi.resize(n + 1);
	f[1] = 0;
	pi[1] = "";
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
		if (a <= b && a <= c) {
			f[i] = a;
			pi[i] = pi[i - 1] + "1";
		} else if (b <= a && b <= c) {
			f[i] = b;
			pi[i] = pi[i / 2] + "2";
		} else {
			f[i] = c;
			pi[i] = pi[i / 3] + "3";
		}
	}
	cout << pi[n] << '\n';
}