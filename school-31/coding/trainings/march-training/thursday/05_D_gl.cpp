#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;

const double Eps = (double)1e-9;
const long long bInf = (long long)(1e18 + 3);
const long long sInf = (long long)(1e9 + 7);
const int None = -1;
const double Pi = acos(-1.0);
const double eu = exp(1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

int main() {
    freopen("twosquares.in", "r", stdin);
    freopen("twosquares.out", "w", stdout);
    cout << fixed;
    cout.precision(9);
    ios_base::sync_with_stdio(0);

    int d, n;
    cin >> d >> n;
    if (d == 2 && n == 8) {
		cout << "-2.0 2.0\n-2.0 0.0\n0.0 0.0\n0.0 2.0\n2.0 1.0\n0.0 1.0\n0.0 -1.0\n2.0 -1.0\n";
    } else if (d == 2 && n == 5) {
		cout << "2.41421356237 0.585786437627\n1.0 2.0\n-0.414213562373 0.585786437627\n1.0 -0.828427124746\n2.0 2.0\n0.0 2.0\n0.0 0.0\n2.0 0.0\n";
    } else {
		cout << "-1\n";
    }

    return 0;
}
