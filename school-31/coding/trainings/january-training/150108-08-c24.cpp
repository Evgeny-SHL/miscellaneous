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

vector<int> divs;

long long cmp_srch(int prev, int ind, int m, int k, int n, int cur_p) {
//	cout << "st = " << prev << " " << k << '\n';
	long long ans = 0;
	for (int i = ind; i < m; ++i) {
		if (gcd(prev, divs[i]) == 1 && cur_p * divs[i] <= n) {
			if (i < m && k > 1) {
			//	cout << "to " << divs[i] << '\n';
				ans += cmp_srch(divs[i], i + 1, m, k - 1, n, cur_p * divs[i]);
			}
			if (k == 1) {
			//	cout << "pl " << divs[i] << '\n';
				ans += 1;
			}
		} else if (cur_p * divs[i] > n) {
			break;
		}
	}
	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;
	long long ans;
	for (int i = 1; i <= (int)sqrt(n - 1); ++i) {
		if (n % i == 0) {
			int j = n / i;
			divs.push_back(i);
			divs.push_back(j);
	}
	}
	if ((int)sqrt(n) * (int)sqrt(n) == n) {
		divs.push_back((int)sqrt(n));
	}
	sort(divs.begin(), divs.end());
	int m = (int)divs.size();
	/*for (int i = 0; i < m; ++i) {
		cout << divs[i] << " ";
	}
	cout << '\n';*/
	ans = 0;
	for (int i = 0; i < m - 1; ++i) {
		ans += cmp_srch(divs[i], i + 1, m, k - 1, n, divs[i]);
	}
	cout << ans << '\n';
    return 0;
}

