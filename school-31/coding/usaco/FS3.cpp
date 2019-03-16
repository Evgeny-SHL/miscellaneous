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

int n;
vector<int> id;
vector< vector<long long> > good;
vector< bitset<Max> > our;
bitset<Max> used(0);

long long gen(int k, int r, int c, bitset<Max> used, long long cur) {
	if (k == 0 && used.count() == n) {
		return cur;
	} else if (k == 0 || n - used.count() > 2 * k) {
		return 0;
	}
	long long res = 0;
	bitset<Max> u_copy = used;
	for (int i = r; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (our[i][j] || (i == r && j <= c) || j <= i) {
				continue;
			}
			our[i][j] = 1;
			u_copy[i] = 1;
			u_copy[j] = 1;
			res = max(res, gen(k - 1, i, j, u_copy, cur + good[i][j]));
			our[i][j] = 0;
			u_copy[i] = used[i];
			u_copy[j] = used[j];
		}
	}
	return res;
}

int main() {

	fin >> n;

	id.resize(n);
	our.resize(n, bitset<Max>(0));
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

	our.resize(n, bitset<Max>(0));
	fout << gen(n - 1, 0, 0, used, 0);

	return 0;
}