#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<long long> b;
long long INF = 1e9 + 7;
map<long long, int> cnt;

int main() {
	int N, l, r, m, ml, mn;
	long long a, K;

	fin >> N >> K;

	b.assign(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		fin >> a;
		b[i] = a + b[i - 1];
		cnt[b[i]] = i + 1;
	}

	ml = 0;
	mn = 0;
	for (int l = 1; l <= N; ++l) {
		if (cnt.find(b[l - 1] + K) != cnt.end()) {
			r = cnt[b[l - 1] + K];
			if (r - l > mn) {
				ml = l;
				mn = r - l;
			}
		}
	}

	fout << ml << " " << mn << "\n";

	return 0;
}