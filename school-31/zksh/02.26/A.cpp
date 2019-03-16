#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

long long ans[23];
const int dx[4] = { 0, -1, 1, 0 };
const int dy[4] = { -1, 0, 0, 1 };
vector< vector<bool> > used;

long long gen(int k, int x, int y, int prev) {
//	cout << k << " " << x << " " << y << " " << prev << "\n";
	if (k == 0) {
		return 1;
	}
	long long res = 0;
	for (int i = 0; i < 4; ++i) {
		if (i != prev) {
			if (!used[x + dx[i]][y + dy[i]]) {
				used[x + dx[i]][y + dy[i]] = true;
				res += gen(k - 1, x + dx[i], y + dy[i], 3 - i);
				used[x + dx[i]][y + dy[i]] = false;
			}
		}
	}
	return res;
}

int main() {

#ifdef DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n;
	/*for (int n = 0; n <= 22; ++n) {
		if (n == 0) {
			cout << "ans[" << n << "] = " << "1;\n";
		} else if (n == 1) {
			cout << "ans[" << n << "] = " << "4;\n";
		} else {
			used.assign(50, vector<bool>(50, false));
			long long ans = 0;
			used[25][25] = true;
			used[25][26] = true;
			used[25][27] = true;
			ans += 4 * gen(n - 2, 25, 27, 0);
			used[25][27] = false;
			used[26][26] = true;
			ans += 8 * gen(n - 2, 26, 26, 1);
			cout << "ans[" << n << "] = " << ans << ";\n";
		}
	}*/
	ans[0] = 1;
	ans[1] = 4;
	ans[2] = 12;
	ans[3] = 36;
	ans[4] = 100;
	ans[5] = 284;
	ans[6] = 780;
	ans[7] = 2172;
	ans[8] = 5916;
	ans[9] = 16268;
	ans[10] = 44100;
	ans[11] = 120292;
	ans[12] = 324932;
	ans[13] = 881500;
	ans[14] = 2374444;
	ans[15] = 6416596;
	ans[16] = 17245332;
	ans[17] = 46466676;
	ans[18] = 124658732;
	ans[19] = 335116620;
	ans[20] = 897697164;
	ans[21] = 2408806028;
	ans[22] = 6444560484;
	cin >> n;
	cout << ans[n] << "\n";
	return 0;
}