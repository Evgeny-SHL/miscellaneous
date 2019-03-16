#include <fstream>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <algorithm>
using namespace std;

ifstream fin("hopscotch.in");
ofstream fout("hopscotch.out");

const long long Inf = (long long)1000000007;
const double Eps = (double)1e-9;

vector< vector<int> > field, dp;

int main() {
	int n, m, k;

	fin >> n >> m >> k;

	field.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; ++i) {
		field[i].resize(m);
		dp[i].resize(m);
		for (int j = 0; j < m; ++j) {
			fin >> field[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int r = i + 1; r < n; ++r) {
				for (int c = j + 1; c < m; ++c) {
					if (field[r][c] != field[i][j]) {
					//	cout << r << " " << c << " " << i << " " << j << "\n";
						dp[r][c] = (dp[i][j] + dp[r][c]) % Inf;
					}
				}
			}
		}
	}

	fout << dp[n - 1][m - 1] << "\n";

	return 0;
}