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

ifstream fin("superbull.in");
ofstream fout("superbull.out");

const long long Inf = (long long)1e18;
const double Eps = (double)1e-9;
const int Max = 2000;

vector<int> id;
vector< vector<long long> > good, dp;

long long powb(int i) {
	long long k = (long long)i;
	return (1LL << i);
}

int main() {
	int n;

	fin >> n;

	id.resize(n);
	good.resize(n);
	for (int i = 0; i < n; ++i) {
		good[i].resize(n);
		fin >> id[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			good[i][j] = id[i] ^ id[j];
		}
	}

	long long k = powb(n);

	dp.resize(n, vector<long long>(k, -1000));
	dp[0][0] = 0;
	for (int turn = 0; turn < n - 1; ++turn) {
		for (long long mask = 0; mask < k; ++mask) {
			for (int i = 0; i < n - 1; ++i) {
				for (int j = i + 1; j < n; ++j) {
					long long nmask = mask | powb(i) | powb(j);
					if (nmask == mask) {
						continue;
					}
					if (dp[turn][mask] > -1000) {
						dp[turn + 1][nmask] = max(dp[turn + 1][nmask], dp[turn][mask] + good[i][j]);
					}

				}
			}
		}
	}

//	for (int turn = 0; turn <= n - 1; ++turn) {
//		for (long long mask = 0; mask < k; ++mask) {
//			cout << turn << " " << mask << "\n";
//			cout << dp[turn][mask] << "\n";
//		}
//	}

	fout << dp[n - 1][k - 1] << "\n";

	return 0;
}