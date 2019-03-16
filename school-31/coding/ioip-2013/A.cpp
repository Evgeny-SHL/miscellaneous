#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

const long long bInf = (long long)(1e18 + 3);
const int sInf = (int)(1e9 + 7);
const double Eps = (double)(1e-9);
const int None = -1;
const double Eur = exp(1.0);
const double Pi = acos(-1.0);
const double Phi = (1.0 + sqrt(5.0)) / 2.0;

vector< vector<char> > face;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	srand(time(0));
	cout << fixed;
	cout.precision(9);
	ios_base::sync_with_stdio(0);

	int n, m, ans;

	cin >> n >> m;
	face.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		face[i].resize(m + 1);
		for (int j = 1; j <= m; ++j) {
			cin >> face[i][j];
		}
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i < n && face[i][j] == '.' && face[i + 1][j] == '.') {
				++ans;
			}
			if (j < m && face[i][j] == '.' && face[i][j + 1] == '.') {
				++ans;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}
