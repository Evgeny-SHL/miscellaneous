#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;



ifstream fin("input.txt");
ofstream fout("output.txt");

const long long Max = (int)1e9;

vector<long long> len;

long long sCount(long long l, int n) {
	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		res += len[i] / l;
	}
	return res;
}

int main() {
	long long n, k;
	long long l, r;

	fin >> n >> k;
	len.resize(n + 1);
	for(int i = 1; i <= n; ++i) {
		fin >> len[i];
	}

	l = 1;
	r = 10000000;
	while (l < r) {
		long long m = (l + r) / 2;
	//	cout << sCount(m, n) << " " << m << "\n";
		if (sCount(m, n) >= k) {
			l = m + 1;
		} else {
			r = m;
		}
	}

	fout << l - 1 << "\n";

	return 0;
}
