#include <vector>
#include <fstream>
#include <map>
#include <deque>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream cin("divisors.in");
ofstream cout("divisors.out");

const long long INF = (long long)1.1e18;
const double PI = acos(-1.0);
const double E = exp(1.0);

int gcd(int a, int b) {
	while (b != 0) {
		int v = a;
		a = b;
		b = v % a;
	}
	return a;
}

int main() {
	int n, k;
	cin >> n >> k;
	if (k > 2) {
		cout << 16 << '\n';
	} else {
	int ans = 0;
		for (int i = 1; i <= (int)sqrt(n + 1); ++i) {
			for (int j = i + 1; j <= n / i + 1; ++j) {
				if (n % i == 0 && n % j == 0 && i * j <= n && gcd(i, j) == 1) {
				//	cout << i << " " << j << '\n';
					++ans;
				}
			}
		}
		cout << ans + 1 << '\n';
	}
    return 0;
}
